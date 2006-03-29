#!/bin/sh
NIGHTLYDIR=/home/gfk/lcdproc/nightly
CVS=/usr/bin/cvs
MAKE=/usr/bin/make
DATE=`/bin/date`
PERL=/usr/bin/perl
GUNZIP=/bin/gunzip
BZIP2=/usr/bin/bzip2
CVS2CL=/home/gfk/lcdproc/cvs2cl.pl
SCP=/usr/bin/scp
RSYNC=/usr/bin/rsync
#####
# Branch, can be stable-0-4-x or current
BRANCH=$1

cd ${NIGHTLYDIR}/${BRANCH}/

# Clean up (just in case)
rm -f lcdproc-*.tar.gz

# Fetch of the changes
${CVS} update -d &> nightly-cvsChanges.txt

# Add of the warning and changes to the README file
mv README README.temp
echo "################################################" > README
echo "# WARNING! WARNING! WARNING! WARNING! WARNING! #" >> README
echo "#                                              #" >> README
echo "# This is an automated nightly distribution    #" >> README
echo "# made with the ${BRANCH} CVS branch." >> README
echo "# Date:   ${DATE}         #" >> README
echo "# NO WARANTIES AT ALL.  Expect this to crash.  #" >> README
echo "# Please report problems to the mailing list.  #" >> README
echo "#                                              #" >> README
echo "#      http://lcdproc.omnipotent.net/          #" >> README
echo "################################################" >> README
echo >> README
cat README.temp >> README
echo "Here's what CVS update said (Check ChangeLog for more infos):" >> README
cat nightly-cvsChanges.txt >> README

# Produce a ChangeLog for yesterday
mv ChangeLog ChangeLog.temp
${CVS2CL} "-d'1 day ago<1 second ago'" --file nightly-ChangeLog &>/dev/null
echo "Changes since yesterday:" > ChangeLog
touch nightly-ChangeLog
cat nightly-ChangeLog >> ChangeLog

# Change the version number to CVS-${BRANCH}-${DATE}
cp configure.in configure.in.temp
BRANCH=${BRANCH} \
${PERL} -MPOSIX -i -p -e '$version = "CVS-".$ENV{BRANCH}."-".strftime("%Y%m%d", localtime);
                          s/(AM_INIT_AUTOMAKE\s*)\(\s*(\[?lcdproc\]?)\s*,\s*[\w\d.-]+\s*\)/$1($2, $version)/; 
                          s/(AC_INIT\s*)\(\s*(\[?lcdproc\]?)\s*,\s*[\w\d.-]+\s*\)/$1($2, $version)/;
                          s/(AC_INIT\s*)\(\s*(\[?lcdproc\]?)\s*,\s*[\w\d.-]+(\s*[^)]+)\s*\)/$1($2, $version$3)/;' \
        configure.in

# Increase version number in debian/changelog accordingly
# use 0.4.99+cvs.... for 0.5pre nightlies to be able to stay in the epoch when moving to 0.5
for dir in debian scripts/debian ; do
  if [ -d i"$dir" ] && [ -e "$dir/changelog" ; then 
    cp $dir/changelog $dir/changelog.temp
    ${PERL} -MPOSIX -i -p -e '$date = strftime("%Y%m%d", localtime);
                              s/\(0\.4\.99\+cvs\d{8}\)/(0.4.99+cvs$date)/i if ($. == 1);' \
            $dir/changelog
  fi
done 

# Make debian/rules executable
for dir in debian scripts/debian ; do
  test -e $dir/rules  &&  chmod +x $dir/rules
done

# Re-generate the autotools files
sh autogen.sh >/dev/null
./configure --silent >/dev/null

# Creation of the distribution
${MAKE} dist >/dev/null &>/dev/null
mv lcdproc-*.tar.gz lcdproc-CVS-${BRANCH}.tar.gz

# Make bzip2 archive
# ${GUNZIP} --stdout lcdproc-CVS-${BRANCH}.tar.gz > lcdproc-CVS-${BRANCH}.tar
# ${BZIP2} lcdproc-CVS-${BRANCH}.tar

# Upload
# scp -qB -i ${NIGHTLYDIR}/id_dsa lcdproc-CVS-${BRANCH}.tar.gz lcdproc-CVS-${BRANCH}.tar.bz2 gfk@lcdproc.sourceforge.net:www-lcdproc/nightly/
#${SCP} -qB \
${RSYNC} -q \
lcdproc-CVS-${BRANCH}.tar.gz gfk@lcdproc.sourceforge.net:www-lcdproc/nightly/
${RSYNC} -q \
lcdproc-CVS-${BRANCH}.tar.gz gfk@cf-shell.sourceforge.net:smoketest/

# Cleanup
mv configure.in.temp configure.in
mv README.temp README
mv ChangeLog.temp ChangeLog
rm -f nightly-ChangeLog
rm -f nightly-cvsChanges.txt
for dir in debian scripts/debian ; do
  test -e $dir/changelog.temp && mv $dir/changelog.temp $dir/changelog
done  
#mv lcdproc-CVS-${BRANCH}.tar.bz2 ../
mv lcdproc-CVS-${BRANCH}.tar.gz ../
sh autogen.sh >/dev/null
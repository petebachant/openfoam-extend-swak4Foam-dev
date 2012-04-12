#! /usr/bin/env python

import sys
from os import path
import re
readme=open(path.join(path.dirname(sys.argv[0]),"..","README"))

reldate="no date"
verstring="undefined"
extension=""

verline=re.compile("\*\* (.+) - version number : (.+)")

for l in readme.readlines():
    m=verline.match(l)
    if m:
        reldate=m.group(1)
        grp=m.group(2).split()
        verstring=grp[0]
        extension=" ".join(grp[1:])

vmajor,vminor,vpatch=verstring.split(".")

versionH=path.join(path.dirname(sys.argv[0]),
                   "..",
                   "Libraries",
                   "swak4FoamParsers",
                   "swakVersion.H")

oldContent=open(versionH).read()

new=["// automatically generated by %s" % path.basename(sys.argv[0])]
new.append('#define SWAK_VERSION_STRING "%s"' % verstring)
new.append("#define SWAK_VERSION_MAJOR %s" % vmajor)
new.append("#define SWAK_VERSION_MINOR %s" % vminor)
new.append("#define SWAK_VERSION_PATCH %s" % vpatch)
new.append('#define SWAK_RELEASE_DATE "%s"' % reldate)
if extension!="":
    new.append('#define SWAK_VERSION_EXTENSION "%s"' % extension)

newContent="\n".join(new)+"\n"

if newContent!=oldContent:
    print "Contents of",versionH,"differ ... writing"
    open(versionH,"w").write(newContent)

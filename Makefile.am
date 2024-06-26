ACLOCAL_AMFLAGS = -I m4

SUBDIRS= \
aggregator \
anonymizer \
backscatter \
biflow_aggregator \
debug_sender \
device_classifier \
email_reporter \
flow_age_stats \
flowcounter \
flow_meter \
ipv6stats \
json_dump \
json_replay \
link_traffic \
logger \
logreplay \
merger \
mux \
demux \
natpair \
prefix_tags \
proto_traffic \
pdns_exporter \
report2idea \
resolver \
sni_dataset_saver \
topn \
traffic_repeater \
unirec2json \
endiverter \
googletest_example

EXTRA_DIST = AUTHORS COPYING ChangeLog INSTALL NEWS README.md nfreader \
	debian/README.Debian \
	debian/changelog \
	debian/compat \
	debian/control \
	debian/copyright \
	debian/nemea-modules-dev.install \
	debian/nemea-modules.install \
	debian/patches \
	debian/rules \
	debian/source \
	debian/watch

if HAVE_LIBNF
SUBDIRS += nfreader
SUBDIRS += nfwriter
endif

if HAVE_LIBLUA
SUBDIRS += luamodule
endif

if HAVE_BISON
SUBDIRS += unirecfilter
if HAVE_OPENSSL
SUBDIRS += scalar-aggregator
endif
endif

if HAVE_LIBCURL
SUBDIRS += bloom_history
endif

RPMDIR = RPMBUILD

if MAKE_RPMS
RPMFILENAME=$(PACKAGE_NAME)-$(VERSION)
.PHONY: srpm
srpm:
	rm -rf "$(RPMDIR)/SOURCES/$(RPMFILENAME)"
	mkdir -p $(RPMDIR)/BUILD/ $(RPMDIR)/SRPMS/ $(RPMDIR)/RPMS/ $(RPMDIR)/SOURCES
	make ${AM_MAKEFLAGS} distdir='$(RPMDIR)/SOURCES/$(RPMFILENAME)' distdir
	( cd "$(RPMDIR)/SOURCES/"; tar -z -c -f $(RPMFILENAME)-$(RELEASE).tar.gz $(RPMFILENAME); rm -rf $(RPMFILENAME); )
	$(RPMBUILD) -bs $(PACKAGE_NAME).spec --define "_topdir `pwd`/$(RPMDIR)";

.PHONY: rpm
rpm: srpm
	$(RPMBUILD) --define "_topdir `pwd`/$(RPMDIR)" --rebuild $(RPMDIR)/SRPMS/$(RPMFILENAME)-$(RELEASE).src.rpm;
else
endif

rpm-clean:
	rm -rf $(RPMDIR)

if MAKE_DEB
.PHONY: deb
deb:
	make distdir && cd nemea-modules-@VERSION@ && debuild -i -us -uc -b
else
endif

deb-clean:
	rm -rf nemea-modules_*.build* nemea-modules_*.changes nemea-modules*.deb nemea-modules_*.orig.tar.gz nemea-modules-*.tar.gz nemea-modules-@VERSION@

clean-local: rpm-clean deb-clean


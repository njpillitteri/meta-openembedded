SUMMARY = "Simple powerful teting with python"
HOMEPAGE = "http://pytest.org"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=640061b8cee64b308a4d2f9f556c12f2"

SRC_URI[md5sum] = "06cdb939a1f45f6b82b304abb87c3e30"
SRC_URI[sha256sum] = "f67403f33b2b1d25a6756184077394167fe5e2f9d8bdaab30707d19ccec35427"

SRC_URI_append = " file://0001-setup.py-remove-the-setup_requires-for-setuptools-scm.patch \
                   "

inherit update-alternatives

RDEPENDS_${PN}_class-target += " \
    ${PYTHON_PN}-attrs \
    ${PYTHON_PN}-debugger \
    ${PYTHON_PN}-doctest \
    ${PYTHON_PN}-json \
    ${PYTHON_PN}-pluggy \
    ${PYTHON_PN}-py \
    ${PYTHON_PN}-setuptools \
    ${PYTHON_PN}-six \
    ${PYTHON_PN}-atomicwrites \
    ${PYTHON_PN}-importlib-metadata \
    ${PYTHON_PN}-pathlib2 \
    ${PYTHON_PN}-wcwidth \
    ${PYTHON_PN}-more-itertools \
    ${PYTHON_PN}-packaging \
"

FILESEXTRAPATHS_prepend := "${THISDIR}/python-pytest:"

ALTERNATIVE_${PN} += "py.test pytest"

NATIVE_LINK_NAME[pytest] = "${bindir}/pytest"
ALTERNATIVE_TARGET[pytest] = "${bindir}/pytest"

ALTERNATIVE_LINK_NAME[py.test] = "${bindir}/py.test"
ALTERNATIVE_TARGET[py.test] = "${bindir}/py.test"

BBCLASSEXTEND = "native nativesdk"

### R/qtl2convert

[![Build Status](https://travis-ci.org/rqtl/qtl2convert.svg?branch=master)](https://travis-ci.org/rqtl/qtl2convert)

[Karl Broman](http://kbroman.org)

[R/qtl2](http://kbroman.org/qtl2) (aka qtl2) is a reimplementation of
the QTL analysis software [R/qtl](https://rqtl.org), to better handle
high-dimensional data and complex cross designs. It is split into
multiple packages:

- [qtl2geno](https://github.com/rqtl/qtl2geno), for calculating genotype
  probabilities, imputations, and genetic maps
- [qtl2scan](https://github.com/rqtl/qtl2scan), for QTL genome scans and
  related calculations
- [qtl2plot](https://github.com/rqtl/qtl2plot), for data visualization
- [qtl2convert](https://github.com/rqtl/qtl2convert),
  for converting data among the R/qtl2,
  [DOQTL](https://www.bioconductor.org/packages/release/bioc/html/DOQTL.html),
  and [R/qtl](https://rqtl.org) formats
- [qtl2db](https://github.com/rqtl/qtl2db), for connecting to genome databases

---

### Installation

R/qtl2 is not yet available on [CRAN](https://cran.r-project.org), but
it can be installed from a mini-CRAN at [rqtl.org](https://rqtl.org).
Make sure you have the latest version of [R (3.4.2)](https://cran.r-project.org).

    install.packages("qtl2", repos="https://rqtl.org/qtl2cran")

The [qtl2](https://github.com/rqtl/qtl2) package is
inspired by the
[tidyverse package](https://cran.r-project.org/package=tidyverse);
it is basically empty, but when you install it, the
[qtl2geno](https://github.com/rqtl/qtl2geno),
[qtl2scan](https://github.com/rqtl/qtl2scan),
[qtl2plot](https://github.com/rqtl/qtl2plot),
[qtl2convert](https://github.com/rqtl/qtl2convert) and
[qtl2db](https://github.com/rqtl/qtl2db) packages, plus a
bunch of dependencies, will be installed.

Alternatively, you can install R/qtl2 from its source on
[GitHub](https://github.com/rqtl). (But note that compiling the C++
code can be rather slow.)

On _Windows_, you'll need [Rtools](https://cran.r-project.org/bin/windows/Rtools/).

On _Mac OS X_, you'll need the
[command-line developer tools](https://mac-how-to.gadgethacks.com/how-to/install-command-line-developer-tools-without-xcode-0168115/),
as well as [gfortran](https://gcc.gnu.org/wiki/GFortranBinaries#MacOS).

You then need to install the
[devtools](https://github.com/hadley/devtools) package, plus a set of
package dependencies: [yaml](https://cran.r-project.org/package=yaml),
[jsonlite](https://cran.r-project.org/package=jsonlite),
[data.table](https://cran.r-project.org/package=data.table),
[RcppEigen](https://github.com/RcppCore/RcppEigen),
[RSQLite](https://github.com/rstats-db/RSQLite), and
[qtl](https://rqtl.org).
(Additional, secondary dependencies will also be installed.)

    install.packages(c("devtools", "yaml", "jsonlite", "data.table", "RcppEigen", "RSQLite", "qtl"))

Finally, install R/qtl2 using `devtools::install_github()`.

    library(devtools)
    install_github("rqtl/qtl2")

---

#### License

[Licensed](License.md) under [GPL-3](https://www.r-project.org/Licenses/GPL-3).

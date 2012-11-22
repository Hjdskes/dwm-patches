pkgname=dwm
pkgver=6.0
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('i686' 'x86_64')
license=('MIT')
depends=('libxinerama' 'pango')
options=(zipman)
provides=('dwm')
conflicts=('dwm-pango')
_source=(http://dl.suckless.org/dwm/dwm-$pkgver.tar.gz
        config.h)
_patches=(01-dwm-6.0-xft.diff
          02-dwm-6.0-pertag2.diff
          03-dwm-6.0-uselessgaps.diff
		  04-dwm-6.0-systray.diff
		  05-dwm-6.0-statuscolors.diff
		  06-dwm-6.0-occupiedcol.diff
		  07-dwm-6.0-monocle_fixes.diff
		  08-dwm-6.0-statusallmons.diff
		  09-dwm-6.0-attachaside.diff
		  10-dwm-6.0-no_title.diff
		  11-dwm-6.0-remove_unfunc.diff
		  12-dwm-6.0-XKeycodeToKeysym_fix.diff
#		  18-dwm-6.0-transparentbar.diff
          00-dwm-6.0-buildflags.diff)
source=(${_source[@]} ${_patches[@]})

build() {
  for PATCH in "${_patches[@]}"; do
    msg "${PATCH##*/}" && patch -Np1 -i "${startdir}/${PATCH##*/}"
  done

  cd $srcdir/$pkgname-$pkgver
  cp $srcdir/config.h config.h

  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11 || return 1
  make PREFIX=/usr DESTDIR=$pkgdir install || return 1

  install -m644 -D LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE && \
  install -m644 -D README $pkgdir/usr/share/doc/$pkgname/README
}
k

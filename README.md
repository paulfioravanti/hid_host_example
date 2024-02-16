# HID Host Example

This is the codebase for my implementation of a [Human Interface Device][] (HID)
host program in [C][]. It was created using [Plover][] stenography and
[UltiSnips][] snippets, for the [Talking to a Georgi with C \[Steno Coding\]][]
video.

## Setup

```sh
git clone https://github.com/paulfioravanti/hid_host_example.git
cd hid_host_example
```

## Prerequisites

### HIDAPI

The [HIDAPI][] library is required to open up HID communication channels, so
install it with your operating system's package manager. HIDAPI provides some
minimal information about this in their [Installing HIDAPI][] section, but if
you are using macOS, you can install it with [Homebrew][]:

```sh
brew install hidapi
```

### `pkg-config`

Feel free to compile the host as you see fit, but I use [pkg-config][]
([repo][pkg-config repo]) to provide an easier interface to include libraries.
You can install it via your operating system package manager, or use Homebrew if
you use macOS:

```sh
brew install pkg-config
```

## Compile

If you use `pkg-config`, you can use the included build file:

```sh
./build.sh
```

Otherwise, feel free to use it as a guide to make your own.

## Run

```sh
./host
```

## Sibling Repo

For a more robust example of a HID host that I use often, see my [HID Hosts][]
repo.

[C]: https://en.wikipedia.org/wiki/C_(programming_language)
[HIDAPI]: https://github.com/libusb/hidapi
[HID Hosts]: https://github.com/paulfioravanti/hid_hosts
[Homebrew]: https://brew.sh/
[Human Interface Device]: https://en.wikipedia.org/wiki/USB_human_interface_device_class
[Installing HIDAPI]: https://github.com/libusb/hidapi#installing-hidapi
[pkg-config]: https://en.wikipedia.org/wiki/Pkg-config
[pkg-config repo]: https://gitlab.freedesktop.org/pkg-config/pkg-config
[Plover]: http://www.openstenoproject.org/
[Talking to a Georgi with C \[Steno Coding\]]: https://www.youtube.com/watch?v=egReh-6maNw
[UltiSnips]: https://github.com/SirVer/ultisnips

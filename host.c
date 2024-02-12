#include <stdio.h> // printf
#include <wchar.h> // wchar_t
#include <hidapi.h> // hid_*

enum {
  VENDOR_ID = 0xFEED,
  PRODUCT_ID = 0x1337,
  MAX_LENGTH = 255
};

int main(int argc, char *argv[]) {
  hid_init();

  hid_device *handle = hid_open(VENDOR_ID, PRODUCT_ID, NULL);
  if (!handle) {
    printf("Unable to open device\n");
    hid_exit();
    return 1;
  }

  wchar_t manufacturer[MAX_LENGTH];
  hid_get_manufacturer_string(handle, manufacturer, MAX_LENGTH);
  printf("Manufacturer string: %ls\n", manufacturer);

  hid_close(handle);

  hid_exit();

  return 0;
}

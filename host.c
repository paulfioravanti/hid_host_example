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

  hid_device *handle = NULL;
  struct hid_device_info *devices, *current_device;
  devices = hid_enumerate(VENDOR_ID, PRODUCT_ID);
  current_device = devices;

  while (current_device) {
    unsigned short int usage_page = current_device->usage_page;
    unsigned short int usage = current_device->usage;

    printf("Opening -- Usage (page): 0x%hX (0x%hX)...\n", usage, usage_page);
    handle = hid_open_path(current_device->path);

    if (!handle) {
      printf("Unable to open device\n");
      current_device = current_device->next;
      continue;
    }

    printf("Success!\n");
    break;
  }

  if (handle) {
    wchar_t manufacturer[MAX_LENGTH];
    hid_get_manufacturer_string(handle, manufacturer, MAX_LENGTH);
    printf("Manufacturer string: %ls\n", manufacturer);
    hid_close(handle);
  } else {
    printf("Unable to open any devices for 0x%hX:0x%hX\n", VENDOR_ID, PRODUCT_ID);
  }

  hid_exit();

  return 0;
}

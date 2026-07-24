#include <stdint.h>

#include <zmk/endpoints.h>

/* zmk-ruen still uses the pre-2023 endpoints API name. */
int zmk_endpoints_send_report(uint16_t usage_page) {
    return zmk_endpoint_send_report(usage_page);
}

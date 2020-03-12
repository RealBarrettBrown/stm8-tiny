/*!
 * @file
 * @brief
 */

#include "charge.h"
#include "tiny_utils.h"
#include "data_model.h"

static void foo(void* a, void* b) {
  if(a == b) {
    while(1) {
    }
  }
}

static void callback(void* context, const void* args) {
  (void)context;
  (void)args;
}

void charge_init(charge_t* self, i_tiny_key_value_store_t* key_value_store) {
  self->_inner.key_value_store = key_value_store;
  tiny_event_subscription_init(&self->_inner.on_change_subscription, self, callback);
  tiny_event_subscribe(tiny_key_value_store_on_change(key_value_store), &self->_inner.on_change_subscription);
  foo(self, &self->_inner.on_change_subscription);

  tiny_key_value_store_read(self->_inner.key_value_store, key_test, &self->_inner.data);
}

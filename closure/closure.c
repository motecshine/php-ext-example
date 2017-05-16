#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_example.h"
#include "closure/closure.h"

PHP_FUNCTION(closure)
{
    zval retval;
    zend_fcall_info  fci;
    zend_fcall_info_cache  fci_cache;
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_FUNC(fci, fci_cache)
        Z_PARAM_VARIADIC('*', fci.params, fci.param_count)
    ZEND_PARSE_PARAMETERS_END();
    fci.retval = &retval;
    if (zend_call_function(&fci, &fci_cache) == SUCCESS && Z_TYPE(retval) != IS_UNDEF) {
        if (Z_ISREF(retval)) {
            zend_unwrap_reference(&retval);
        }
    }
    ZVAL_COPY_VALUE(return_value, &retval);
}


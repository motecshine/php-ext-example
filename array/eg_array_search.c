#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_example.h"
#include "array/eg_array_search.h"


static void print_var(zval * value, zend_string * key)
{
	switch(Z_TYPE_P(value)){
		case IS_STRING :
			php_printf("find {key:%s value:%s}\n", ZSTR_VAL(key), Z_STRVAL_P(value));
			break;
		case IS_LONG :
			php_printf("find {key:%s value:%ld}\n", ZSTR_VAL(key), Z_LVAL_P(value));
			break;
		default:
			php_printf("value type: {%d}\n", Z_TYPE_P(value));
	}
}

PHP_FUNCTION(eg_array_search)
{
    zval * arr;
    HashTable * arrTable;
    zval * value;
    zend_string * key;
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_ARRAY(arr)
        Z_PARAM_STR(key)
    ZEND_PARSE_PARAMETERS_END();
    arrTable = Z_ARRVAL_P(arr);
    if ((value = zend_hash_find(arrTable, key)) != NULL) {
		print_var(value, key);
    } else {
		php_printf("undefined\n");
	}
}


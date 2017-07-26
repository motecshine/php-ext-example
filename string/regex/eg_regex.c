#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_example.h"
#include "string/regex/eg_regex.h"

ZEND_BEGIN_ARG_INFO(eg_regex_arg_info, 0)
    ZEND_ARG_INFO(0, origin_str)
    ZEND_ARG_INFO(0, regex_rule)
ZEND_END_ARG_INFO()

PHP_FUNCTION(eg_regex)
{
    zend_string * origin_str, * regex_rule;
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_STR(origin_str)
        Z_PARAM_STR(regex_rule)
    ZEND_PARSE_PARAMETERS_END();
}

/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2017 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_example.h"
#include "closure/closure.h"
#include "array/eg_array_search.h"
ZEND_BEGIN_ARG_INFO(closure_arg_info, 0)
    ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(eg_array_search_arg_info, 0)
	ZEND_ARG_INFO(0, arr)
    ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()
/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(example)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(example)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(example)
{
#if defined(COMPILE_DL_EXAMPLE) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(example)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(example)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "example support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ example_functions[]
 *
 * Every user visible function must have an entry in example_functions[].
 */
const zend_function_entry example_functions[] = {
	PHP_FE(eg_array_search, eg_array_search_arg_info)
	PHP_FE(closure, closure_arg_info)
	PHP_FE_END	/* Must be the last line in example_functions[] */
};
/* }}} */

/* {{{ example_module_entry
 */
zend_module_entry example_module_entry = {
	STANDARD_MODULE_HEADER,
	"example",
	example_functions,
	PHP_MINIT(example),
	PHP_MSHUTDOWN(example),
	PHP_RINIT(example),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(example),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(example),
	PHP_EXAMPLE_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_EXAMPLE
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(example)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

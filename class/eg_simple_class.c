#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "./php_example.h"
#include "class/eg_simple_class.h"

PHP_METHOD(SimpleClass, helloWorld)
{
    php_printf("hello world!!!\n");
}

const zend_function_entry simple_class_methods[] = {
    PHP_ME(SimpleClass, helloWorld,        NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_EXAMPLE_STARTUP_FUNCTION(SimpleClass)
{
    zend_class_entry simple_class_container_ce;
    INIT_CLASS_ENTRY(simple_class_container_ce, "Example\\SimpleClass", simple_class_methods);
    zend_register_internal_class(&simple_class_container_ce);
    return SUCCESS;
}
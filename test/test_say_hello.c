#define CHEAT_NO_MATH

#include "cheat.h"
#include "cheats.h"
#include "say_hello.h"

CHEAT_TEST(greeting_works,
           cheat_assert_string("Hello Michael", say_hello("Michael"));
);

CHEAT_TEST(greeting_with_big_names_works,
           cheat_assert_string(
		           "Hello Pablo Diego José Francisco de Paula Juan Nepomuceno Cipriano de la Santísima Trinidad Ruiz Picasso",
		           say_hello(
				           "Pablo Diego José Francisco de Paula Juan Nepomuceno Cipriano de la Santísima Trinidad Ruiz Picasso"));
);

/*
 *  Copyright 2015 Matus Chochlik.
 */

//[example_namespaces
#include __reflexpr_header
#include <iostream>

namespace foo { namespace bar { } }

namespace foobar = foo::bar;

int main(void)
{
	using namespace std;

	typedef __reflexpr(foo) meta_foo; /*<
	Reflected namespace [^foo].
	>*/

	static_assert(__is_metaobject_v<meta_foo>, "");

	static_assert(!__meta::__is_global_scope_v<meta_foo>, "");
	static_assert(meta::__is_namespace_v<meta_foo>, "");
	static_assert(!meta::__is_type_v<meta_foo>, "");
	static_assert(!meta::__is_alias_v<meta_foo>, "");

	static_assert(meta::__has_name_v<meta_foo>, "");
	static_assert(meta::__has_scope_v<meta_foo>, "");
	cout << meta::__get_name_v<meta_foo> << endl;

	typedef reflexpr(foo::bar) meta_foo_bar; /*<
	Reflected nested namespace [^foo::bar].
	>*/

	static_assert(is_metaobject_v<meta_foo_bar>, "");

	static_assert(!meta::is_global_scope_v<meta_foo_bar>, "");
	static_assert(meta::is_namespace_v<meta_foo_bar>, "");
	static_assert(!meta::is_type_v<meta_foo_bar>, "");
	static_assert(!meta::is_alias_v<meta_foo_bar>, "");

	static_assert(meta::has_name_v<meta_foo_bar>, "");
	static_assert(meta::has_scope_v<meta_foo_bar>, "");
	cout << meta::get_name_v<meta_foo_bar> << endl;

	typedef reflexpr(foobar) meta_foobar; /*<
	Reflected namespace alias [^foobar].
	>*/

	static_assert(is_metaobject_v<meta_foobar>, "");

	static_assert(!meta::is_global_scope_v<meta_foobar>, "");
	static_assert(meta::is_namespace_v<meta_foobar>, "");
	static_assert(!meta::is_type_v<meta_foobar>, "");
	static_assert(meta::is_alias_v<meta_foobar>, "");

	static_assert(meta::has_name_v<meta_foobar>, "");
	static_assert(meta::has_scope_v<meta_foobar>, "");
	cout << meta::get_name_v<meta_foobar> << " a.k.a ";
	cout << meta::get_name_v<meta::__get_aliased_t<meta_foobar>> << endl;

	return 0;
}
//]

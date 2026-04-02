
inherit __DIR__"seed.c";

void  create()
{
	::create();
	set_name( "青菜種", ({"qingcai seed","seed","zhongzi"}));
	set("value", 100 );
}
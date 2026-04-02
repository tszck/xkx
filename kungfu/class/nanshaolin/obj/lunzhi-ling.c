// Last Modified by Winder on May. 29 2001
// lunzhi-ling
inherit ITEM;

void create()
{
	set_name( "輪值令", ({ "lunzhi ling", "ling", "iron" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "塊");
		set("long", "這是一塊用於南少林輪值用的令牌。\n");
		set("value", 100);
		set("material", "iron");
	}
	setup();
}

void init()
{
	call_out("dest", 900);
}

void dest()
{
	destruct(this_object());
}

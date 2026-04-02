// book-xisui.c
// Last Modified by winder on May. 29 2001

inherit ITEM;

void create()
{
	set_name("洗髓經", ({ "xisui", "shu", "book" }));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "卷");
		set("long","這是一卷暗紅色的破布，裏面密密麻麻的畫了不少打坐吐吶的姿勢。\n");
                set("treasure", 1);
		set("value", 500);
		set("material", "cloth");
	}
}

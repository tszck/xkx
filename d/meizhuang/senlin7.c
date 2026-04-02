// /d/meizhuang/senlin7.c
// Last Modified by winder on Apr. 10 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "百木園");
	set("long", @LONG
這裏是梅莊的百木園，你一走到這裏，就象走到了一個連綿無盡的
小森林一樣，這裏無數的松樹，柏樹，白楊，還有很多叫不出來名字的
異種苗木，你走在其中，只想把這片樹林盡情的欣賞一遍，永不出去才
好。
LONG
	);
	set("exits", ([
		"east"  : __DIR__"senlin"+(random(8)+1),
		"west"  : __DIR__"senlin"+(random(8)+1),
		"south" : __DIR__"senlin"+(random(8)+1),
		"north" : __DIR__"senlin"+(random(8)+1),
	]));
	set("outdoors", "meizhuang");
	set("coor/x", 3500);
	set("coor/y", -1420);
	set("coor/z", 10);
	setup();
}

void init()
{
	object ob = this_player(), room = this_object();
	mapping fam;
	int i = random(2);

	if( i == 0) return;
	if (ob->query("id") == "jia ding" || !living(ob)) return;
	room->delete("exits");

	if ( (fam = ob->query("family")) &&
		fam["family_name"] == "黑木崖" &&
		ob->query("guilty") != 1 )
		ob->set("guilty",3);
	ob->set("startroom", "/d/meizhuang/jianyu");
	message_vision(HIR "\n$N腳下一滑，全身都埋進了厚厚的松針中！
$N只覺得天旋地轉，呼吸也開始困難起來。\n\n" NOR, ob);
	message_vision(HIR "\n$N幾乎就暈了過去......\n\n" NOR, ob);
	call_out("trapping", 20, ob, room);
}

void trapping(object ob, object room)
{
	if ( !living(ob) ) return;

	message_vision(HIY "\n家丁們把$N一把抓住，捆了個結實，扔進了監獄。\n\n\n" NOR, ob);
	ob->move(__DIR__"jianyu");
	room->set("exits/south", __DIR__"senlin"+(random(8)+3));
	room->set("exits/north", __DIR__"senlin"+(random(8)+3));
	room->set("exits/east",  __DIR__"senlin"+(random(8)+3));
	room->set("exits/west",  __DIR__"senlin"+(random(8)+3));
}

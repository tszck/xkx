// Room: /d/nanshaolin/bydian.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "白衣殿");
	set("long", @LONG
這是白衣殿，供奉白衣觀音大士。大士高居須彌座上，手託淨瓶，
眉含微愁，脣綻淺笑，彷彿對人間疾苦既存憂心，又覺釋懷。殿中放了
紅木大香案，香案上供品齊備，香火十分旺盛。
LONG );
	set("exits", ([
		"west" : __DIR__"kchang",
	]));
	set("no_clean_up", 0);
	set("outdoors","nanshaolin");
	set("coor/x", 1830);
	set("coor/y", -6100);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}




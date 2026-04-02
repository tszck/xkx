// Room: /d/shaolin/bydian.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "白衣殿");
	set("long", @LONG
這是白衣殿，供奉白衣觀音大士。大士高居須彌座上，手託
淨瓶，眉含微愁，脣綻淺笑，彷彿對人間疾苦既存憂心，又覺釋
懷。殿中放了紅木大香案，香案上供品齊備，香火十分旺盛。
LONG );
	set("exits", ([
		"west" : __DIR__"guangchang5",
	]));
        set("objects",([
                   __DIR__"npc/mu-ren" : 5
	]));
//	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 910);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}


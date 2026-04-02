// sroad4.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","大雪山口");
        set("long",@LONG
這裏已經到了藏邊，大雪山的山口。大雪山又叫岷山，位於川
藏之間，由於山勢高峻，山頂有終年不化的積雪，故而得名。四下
毫無人跡，只有幾隻禿鷹在高處盤旋，俯視着茫茫雪山。
LONG );
        set("exits",([
                "eastdown"  : __DIR__"sroad3",
                "westup"    : __DIR__"sroad5",
        ]));
        set("objects",([
                __DIR__"npc/eagle": 2,
        ]));
        set("outdoors", "xueshan");
        set("no_clean_up", 0);
	set("coor/x", -50000);
	set("coor/y", -10000);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
// sroad5.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","大雪山口");
        set("long",@LONG
這兒遍地冰雪，你眼前白皚皚的一片。從東邊爬上來的，心跳開始加速。
LONG );
        set("exits",([
                "eastdown"  : __DIR__"sroad4",
                "southup"   : __DIR__"sroad6",
        ]));
        set("objects", ([
                __DIR__"npc/xuebao" : random(2),
        ]));
        set("outdoors", "xueshan");
	set("coor/x", -100000);
	set("coor/y", -10000);
	set("coor/z", 200);
	setup();
	replace_program(ROOM);
}
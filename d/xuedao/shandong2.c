// shandong2.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","洞口");
        set("long",@LONG
山谷裏積雪被攏成幾個雪堆，這裏時常有人掃除積雪。你前面的峭
壁下隱隱約約有一個山洞。
LONG );
        set("exits",([
                "enter" : __DIR__"shandong3",
                "west"  : __DIR__"sroad9",
        ]));
        set("objects", ([
                CLASS_D("xueshan")+"/baoxiang" :1,
        ]));
        set("outdoors", "xueshan");
	set("coor/x", -109900);
	set("coor/y", -55000);
	set("coor/z", 300);
	setup();
        replace_program(ROOM);
}
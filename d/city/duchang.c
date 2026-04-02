// Room: /city/duchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "淮揚賭場");
	set("long", @LONG
這裏是淮揚賭場的大院，煙花三月的揚州，怎麼能少了這個？院子
四周是通往各個房間的通道。隱隱可以聽到傳出來吆五喝六的聲音。你
搖頭一笑，想要的正是這個調調兒。南面搏餅廳，也是本潭的網友聯誼
會，聯誼會四周是搏餅屋。
LONG );
	set("objects", ([
		CLASS_D("shenlong")+"/pang" : 1,
//		"/clone/misc/fifa2002" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"shaiziting",
		"west"  : __DIR__"shilijie2",
		"east"  : __DIR__"zoulang1",
		"south" : __DIR__"bobingting",
	]));
	set("no_clean_up", 0);
	set("outdoors", "duchang");
	set("coor/x", 20);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" && this_player()->query("age")<18)
                return notify_fail("小毛孩子往這兒瞎湊合什麼？\n");
        return ::valid_leave(me, dir);
}

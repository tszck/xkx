//Room: /d/dali/wangfugate.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","王府大門");
	set("long",@LONG
你正站在一座豪華的府門前，門前有兩隻極大的石獅子，門上高
懸一塊橫匾，上書「鎮南王府」四個金字。門口站着兩排侍衞，身着
錦衣，手執鋼刀，氣宇軒昂。
LONG);
	set("objects", ([
	   CLASS_D("dali")+"/zhuwanli": 1,
	   CLASS_D("dali")+"/first": 1,
	   __DIR__"npc/weishi2": 1,
	   __DIR__"npc/weishi1": 2,
	]));
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("outdoors", "daliwang");
	set("exits",([ /* sizeof() == 1 */
	    "enter"  : __DIR__"wfdating",
	    "south"  : __DIR__"wangfulu",
	]));
	set("coor/x", -39000);
	set("coor/y", -70990);
	set("coor/z", 0);
	setup();
	"/clone/board/dali_b"->foo();
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "大理段家") && dir == "enter" &&
                objectp(present("zhu wanli", environment(me))))
           return notify_fail("褚萬裏攔住你説：閒雜人等，別到處亂竄。\n");

        return ::valid_leave(me, dir);
}
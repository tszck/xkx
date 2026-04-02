// Room: /d/taohua/bingqi.c
// Last Modified by winder on Nov. 17 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "兵器室");
	set("long", @LONG
這裏是兵器庫，到處銀光閃閃，讓人眼花繚亂。寶刀、寶劍、金箍
棒，大刀、長劍、哨棒，短刀、短劍、短棍，各色各樣的兵器應有盡有，
你一時不知道挑什麼好。
LONG );
	set("exits", ([
		"north" : __DIR__"bingyin",
	]));
	set("objects", ([
		__DIR__"obj/gangdao": 1,
		__DIR__"obj/gangjian" : 3,
	]) );
//	set("no_clean_up", 0);
        
        create_door("north", "鐵門", "south", DOOR_CLOSED);
	set("coor/x", 20);
	set("coor/y", -62);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	int i, j;
	object *inv;
	inv = all_inventory(me);
	i = sizeof(inv);
	for (i = 0; i < sizeof(inv); i++)
	{
		if (inv[i]->query("id") == "sword") j++;
	}
	if (j > 1)
                return notify_fail("這位" + RANK_D->query_respect(me) + "別那麼貪心，帶走一把鋼劍就夠啦。\n");
        return ::valid_leave(me, dir);
}
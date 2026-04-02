// Room: /d/taohua/bingqi.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "兵器室");
	set("long", @LONG
這是一間存放兵器的屋子。刀、槍、劍、戟等各種兵器都按類放在
各自的兵器架上。整個屋子落滿灰塵，顯然已經好久沒人來過。
LONG );
	set("exits", ([
		"north" : __DIR__"zoulang3",
	]));
	set("objects", ([
		__DIR__"obj/taojian": 5,
		__DIR__"obj/shizi" : 1,
		__DIR__"obj/ziyuxiao" : 1,
		"/clone/weapon/changjian" : 2,
//		__DIR__"npc/machine-bonze" : 4,
	]) );
//	set("no_clean_up", 0);
	set("coor/x", 8990);
	set("coor/y", -3020);
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
		if (inv[i]->query("id") == "taomu jian") j++;
	}
	if (j > 1)
                return notify_fail("這位" + RANK_D->query_respect(me) + "別那麼貪心，帶走一把桃木劍就夠啦。\n");
        return ::valid_leave(me, dir);
}
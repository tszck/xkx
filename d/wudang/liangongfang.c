// liangongfang.c 練功房
// by Xiang

inherit ROOM;

void create()
{
        set("short", "練功房");
        set("long", @LONG
這裏是練功房，地下凌亂地放着幾個蒲團，幾位武當弟子正盤膝坐
在上面打坐。
LONG );
        set("exits", ([
                "west" : __DIR__"donglang2",
        ]));
        set("objects", ([
                "/d/village/obj/zhujian" : 3
        ]));
        set("no_fight", 1);
//        set("no_clean_up", 0);
	set("coor/x", -2020);
	set("coor/y", -920);
	set("coor/z", 90);
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
		if (inv[i]->query("id") == "zhujian") j++;
	}
	if (j > 1)
                return notify_fail("這位" + RANK_D->query_respect(me) + "別那麼貪心，帶走一把竹劍就夠啦。\n");
        return ::valid_leave(me, dir);
}

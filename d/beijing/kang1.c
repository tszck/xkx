// Room: /beijing/kang1.c

inherit ROOM;

void create()
{
	set("short", "康府大門");
	set("long", @LONG
一座富麗堂皇的大宅院出現在你的眼前，兩頭高大的石獅子
鎮住了大門兩側。門外有帶刀侍衞把守，戒備森嚴。門上掛着兩
個燈籠，赫然寫着大大的“康”字。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"south" : __DIR__"wangfu3",
		"north" : __DIR__"kang2",
	]));
	set("objects", ([
		"/d/huanggong/npc/shiwei" : 2,
	]));
	set("coor/x", -180);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
    int i;
    object *inv;
    if(dir=="north")
    {
     if( this_player()->query("meili")>50 )
     {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop")&& (inv[i]->query("equipped")))
		if(objectp(present("shi", environment(me)))&&living(present("shi", environment(me))))
                    return notify_fail("侍衞上前擋住你，朗聲説道：這位" +
                        RANK_D->query_respect(me) + "請放下兵刃。\n"
                        "你可以進府，但不得手持兵刃。\n");
        return ::valid_leave(me, dir);
     }
     else
     {
         if(objectp(present("shi", environment(me)))&&living(present("shi", environment(me))))
            return notify_fail("侍衞攔住你罵道：“你以為你是誰啊？一個尋常百姓，難道還想進府見康大人？！\n你這" + RANK_D->query_rude(me) +"快給我滾遠點兒，不然別怪我不客氣！”\n");
     }
    }	
    return ::valid_leave(me, dir);
}

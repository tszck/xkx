// /d/beijing/aobai2.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "鰲府大門");
	set("long", @LONG
一座富麗堂皇的大宅院出現在你的眼前，兩頭高大的石獅子鎮住了
大門兩側。門額上懸掛一方橫匾，寫着‘滿洲第一勇士鰲拜府’幾個大
字，門外有官兵把守，戒備森嚴。門上掛着兩個燈籠，赫然寫着“鰲”
字。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"east" : __DIR__"aobai1",
		"west" : __DIR__"aobai3",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", -200);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	int i;
	object *inv;
	if(dir=="west")
	{
		if( this_player()->query("meili")>50 )
		{
			inv = all_inventory(me);
			for(i=sizeof(inv)-1; i>=0; i--)
			if(inv[i]->query("weapon_prop") &&
				(inv[i]->query("equipped")))
				if(objectp(present("bing", environment(me))) &&
					living(present("bing",environment(me))))
					return notify_fail("官兵上前擋住你，朗聲説道：這位"+ RANK_D->query_respect(me) + "請放下兵刃。\n你可以進府，但不得手持兵刃。\n");
			return ::valid_leave(me, dir);
		}
		else
		{
			if(objectp(present("guan bing", environment(me))) &&
				living(present("bing", environment(me))))
				return notify_fail("官兵攔住你罵道：“你以為你是誰啊？一個尋常百姓，難道還想進府見鰲大人？！\n你這" + RANK_D->query_rude(me) +"快給我滾遠點兒，不然別怪我不客氣！”\n");
		}
	}	
	return ::valid_leave(me, dir);
}

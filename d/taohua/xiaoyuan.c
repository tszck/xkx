// Room: /d/taohua/xiaoyuan.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "聽簫小院");
	set("long", @LONG
沒有想到這裏竟然會有這麼幽雅的小院，假山迴廊，花樹盆景，無
一不是放置得極爲合適，顯然這裏的主人非常熟悉佈置，再聯繫到東、
西、南三面的桃花陣，足見主人熟通陰陽五行、變化生克之理。北面是
一個小山岡，轉過山岡就是一大片的草地。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east"  : __DIR__"bagua1",
		"west"  : __DIR__"bagua0",
		"south" : __DIR__"taohua1",
		"north" : __DIR__"caodi",
	]) );
	set("objects",([
		CLASS_D("taohua")+"/feng" : 1,
		__DIR__"obj/shizi" : 1,
	]));  
	set("outdoors","taohua");

	set("coor/x", 9010);
	set("coor/y", -3050);
	set("coor/z", 0);
	setup();
}
void init()
{
	object me=this_player();
	if (me->query_temp("step_count"))
	 me->delete_temp("step_count");
}
int valid_leave(object me, string dir)
{
	object *ob, *deep_ob;
	int i, j, drop_flag;

	if (dir == "west" || dir == "east")
	{
		if (!me->query_temp("bagua_1") &&
			me->query_skill("qimen-wuxing", 1) < 90)
			return notify_fail("你感覺這個桃花陣中暗藏八卦，隱隱生出阻力，將你推了回來！\n");
		ob = all_inventory(me);
		drop_flag = 0;
		for(i = 0; i < sizeof(ob); i++)
		{
			if (userp(ob[i]))
			{
				if (!drop_flag)
				{
					message_vision("$N看了看眼前這個複雜無比的八卦陣，決定丟下包袱，輕裝上陣。\n", me);
					drop_flag = 1;
				}
				message_vision("$N將$n從背上放了下來，躺在地上。\n", me, ob[i]);
				ob[i]->move(this_object());
			}
			else
			{
				deep_ob = deep_inventory(ob[i]);
				for(j = 0; j < sizeof(deep_ob); j++)
				{
					if (userp(deep_ob[j]))
					{
						if (!drop_flag)
						{
							message_vision("$N看了看眼前這個複雜無比的八卦陣，決定丟下包袱，輕裝上陣。\n", me);
							drop_flag = 1;
						}
				                message_vision(sprintf("$N丟下一%s$n。\n", ob[i]->query("unit")), me, ob[i]);
						ob[i]->move(this_object());
						break;
					}
				}
			}
		}
	}

	return ::valid_leave(me, dir);
}
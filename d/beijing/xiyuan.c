inherit ROOM;

void create()
{
	set("short", "長安戲院");
	set("long", @LONG
這裏就是著名的長安戲院，幾個戲子在臺上 (stage)唱戲。臺下黑
壓壓的一片都是人。唱到妙處，觀衆們禁不住大聲喝采。東邊是後臺。
LONG );
	set("exits", ([
		"up"    : __DIR__"stage",
		"east"  : __DIR__"houtai",
		"south" : __DIR__"xichang1",
	]));
	set("item_desc", ([
		"stage" : "\n看到戲臺，你突然有種想登臺表演的衝動。\n" ,
	]));
	set("objects", ([
		__DIR__"npc/guanzhong":  5,
	]));
	set("guanzhong", 2);
	set("coor/x", -210);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	int i;
	object man, *ob;
	if(dir=="up")
	{
		if(!me->query_temp("hastryup"))
		{
			me->set_temp("hastryup",1);
			if((int)me->query("meili")>=40)
			{
				message_vision("只聽嘩啦啦一片掌聲，觀衆們一起鼓掌。有人大聲說道：\n靜一靜，請看這位"+RANK_D->query_respect(me)+ "表演。\n",me);
				return ::valid_leave(me, dir);
			}
			else
			{
				if(query("guanzhong") > 0)
				{
					add("guanzhong", -1);
					message_vision("\n突然觀衆一擁而上，對$N大叫道：憑你也敢上臺鬧事？老子宰了你這"+RANK_D->query_rude(me) + "！\n",me);
					if(!present("jia", environment(me)))
					{
						man=new(__DIR__"npc/guanzhong1");
						man->move(this_object());
					}
					if(!present("yi", environment(me)))
					{
						man=new(__DIR__"npc/guanzhong2");
						man->move(this_object());
					}
					if(!present("bing", environment(me)))
					{
						man=new(__DIR__"npc/guanzhong3");
						man->move(this_object());
					}
					if(!present("ding", environment(me)))
					{
						man=new(__DIR__"npc/guanzhong4");
						man->move(this_object());
					}
					if(!present("wu", environment(me)))
					{
						man=new(__DIR__"npc/guanzhong5");
						man->move(this_object());
					}
					ob = all_inventory(this_object());
					for(i=0; i<sizeof(ob); i++)
					{
						if( !userp(ob[i]) )
						{ 
							ob[i]->set_leader(me);
							ob[i]->kill_ob(me);
							me->fight_ob(ob[i]);
						}
					}
				}
				return notify_fail("觀衆們一陣倒彩。\n");
			}
			return notify_fail("觀衆們拼死也不讓你上臺。\n");
		}
		message_vision("$N拼死衝上臺去。\n",this_player());
		return ::valid_leave(me, dir);
		} 
	return ::valid_leave(me, dir);
}

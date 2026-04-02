// Room: /d/village/square.c

inherit ROOM;

void create()
{
        set("short", "打穀場");
        set("long", @LONG
這裏是村子的中心，一個平坦的廣場，每年秋收打穀就在這。廣場東
角有棵大槐樹，平日茶餘飯後，村裏的男女老少都愛聚在這裏談天説地。
角上有幾個大谷堆(gudui)。
LONG );
        set("exits", ([ /* sizeof() == 3 */
		"northwest" : __DIR__"nwroad2",
		"south" : __DIR__"sroad4",
		"east"  : __DIR__"eroad3",
	]));
        set("objects", ([
            __DIR__"npc/kid": 2
        ]) );

//        set("no_clean_up", 0);
        set("outdoors", "village");

	set("coor/x", -970);
	set("coor/y", 270);
	set("coor/z", 0);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
	object me;
	mapping fam;

	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="gudui" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "丐幫" ) 
		{
			message("vision",
				me->name() + "運起丐幫縮骨功，一彎腰往谷堆裏鑽了進去。\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/underxc");
                	message("vision",
				me->name() + "從谷堆裏走了進來。\n",
                		environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("這麼小的洞，你鑽得進去嗎？\n");
	}
}	
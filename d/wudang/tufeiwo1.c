// tufeiwo1.c 林中小路
// by Cleansword 1996/2/2

inherit ROOM;

void create()
{
	set("short", "林中小路");
	set("long", @LONG
你走在一條僻靜的林中小路上，兩旁是陰森森的樹林。只見左右前
後，到處都是鋪天蓋地的松樹林。幾十丈高的大松樹簇在一塊，密實的
枝葉象一蓬蓬巨傘般伸向天空，把陽光遮得絲毫也無。據說這裏經常有
土匪出沒，不可久留。邊上有個小山洞(dong)。
LONG );
	set("outdoors", "sanbuguan");
	set("no_sleep_room",1);
	set("exits", ([
		"south"     : __DIR__"tufeiwo2",
		"northdown" : __DIR__"wdroad10",
	]));
	set("objects", ([
		__DIR__"npc/tufei2" : 2
	]));
	set("coor/x", -2000);
	set("coor/y", -810);
	set("coor/z", 10);
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

	if( arg=="dong" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "丐幫" ) 
		{
			message("vision",
				me->name() + "運起丐幫縮骨功，一彎腰往洞裏鑽了進去。\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/underwd");
                	message("vision",
				me->name() + "從洞裏走了進來。\n",
                		environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("這麼小的洞，你鑽得進去嗎？\n");
	}
}

// Room: /d/shaolin/chufang2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "廚房");
	set("long", @LONG
這裏是一間廚房。廚房很大，可能也是因為兼作倉庫的緣故。
竈頭砌在北首，一根大煙囪直通出屋頂。房子四壁被常年煙火燻得
發黑，連房梁也是焦黑焦黑。牆角堆滿了柴火，另一邊放了些曬乾
的辣椒，稻穀等。東邊的牆灰剝落了一塊，露出犬牙交錯的磚縫來。
屋角邊有個大洞(dong)。
LONG );
	set("exits", ([
		"southwest" : __DIR__"houshan",
	]));
	set("item_desc",([
		"brick"	: "西...東...北...東...南...北...東...西\n",
		"dong"	: "牆角被扒開了個大洞，裏面黑沉沉的，不知通往哪裏。\n"
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 720);
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
			me->move("/d/gaibang/undersl");
                	message("vision",
				me->name() + "從洞裏走了進來。\n",
                		environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("這麼小的洞，你鑽得進去嗎？\n");
	}
}	
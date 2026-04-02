// Room: /d/nanshaolin/fanting1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

string* names = ({
	FOOD_DIR+"mizhi-tianou",
	FOOD_DIR+"jiaxin-biji",
	FOOD_DIR+"basi-shanyao",
	FOOD_DIR+"furong-huagu",
});

void create()
{
	set("short", "飯廳");
	set("long", @LONG
這裏便是少林全寺寺僧用齋的地方。飯廳極大，足可容納上千人同
時進膳。從東到西一排排擺滿了長長的餐桌和長凳，幾位小和尚正來回
忙碌着佈置素齋。桌上擺了幾盆豆腐，花生，青菜以及素鴨等美味素食。
在桌子的一端有一面很小的銅鑼(luo)。東面是個廚房。
LONG );
	set("exits", ([
		"east"  : __DIR__"chufang1",
		"west"  : __DIR__"zhaitang",
		"north" : __DIR__"fanting2",
		"south" : __DIR__"fanting3",
	]));
	set("item_desc", ([
		"luo" : "這是一面銅製的小鑼，是僧人們召喚侍齋的小沙彌用的。\n",
	]));
	set("objects",([
		__DIR__"npc/xiao-nan1" : 1
	]));
	set("coor/x", 1850);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_tap", "qiao");
	add_action("do_tap", "knock");
	add_action("do_zuo", "zuo");
	add_action("do_zuo", "sit");
}

int do_tap(string arg)
{
	object me = this_player();
	object cui;
	if (!arg || (arg != "luo"))
	{
		return notify_fail("你要敲什麼？\n");	
	}
	if( !objectp(cui = present("xiao shami", environment(me))) )
	 	return notify_fail("你敲了一下小鑼，卻發現沒人理你。\n");
	if( !me->query_temp("marks/sit") )  
		return notify_fail("你敲了一下小鑼，鑼聲在飯廳內迴盪，你突然感覺自己很愚蠢。\n");
	if( me->query_temp("marks/served") )
	{
		message_vision("小沙彌對$N説道：我少林寺雖物產甚豐，可也不能象你這樣喫呀！！！\n", me);
		return notify_fail("");
	}
	message_vision("$N端坐在桌前，輕輕敲了一下桌上的小鑼，小沙彌弓身作了個揖，過來招呼。\n", me);
	cui->serve_food(me) ;
	me->set_temp("marks/served", 1);
	remove_call_out("delete_served");
	call_out("delete_served", 10, me);
	return 1;
}

void delete_served(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/served");
}

int do_zuo(string arg)
{
	if ( !arg || (arg != "changdeng" && arg != "chair") )
		return notify_fail("你要坐什麼上面？\n");	
	if (this_player()->query_temp("marks/sit"))
		return notify_fail("你已經有了個座位了。\n");	
	this_player()->set_temp("marks/sit", 1);
	return notify_fail("你找了個空位座下。\n");	
}

int valid_leave(object me, string dir)
{
	me->delete_temp("marks/sit");
	me->delete_temp("tea_cup");
	return ::valid_leave(me, dir);
}


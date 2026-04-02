// /d/taohuacun/caidi1.c
// Last Modifiedy by Zeratul June 2000

#include <ansi.h>
inherit  ROOM;

void harvest( object me, int times );

string  name = "", guarder = "", sort;

void  create()
{
	set("short","菜地");
	set("long", @LONG
這是鄉下路邊的一塊菜地，地裏雜草從生，好象已經荒廢很久了。
地邊有個給守菜地的人擋風雨的小棚子。
LONG
);
	set("exits", ([
		"east" : __DIR__"road1",
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -100);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_seed", "zhong");
	add_action("do_seed", "seed" );
	add_action("do_guard", "observe");
	add_action("do_guard", "shou");
}

int do_seed(string arg)
{

	object  ob, me = this_player();

	if ( name != "" && name != me->query( "id" ) )  return notify_fail( "這塊菜地已經有人種了。\n" );
	if ( name == me->query( "id" ) )  return notify_fail( "你已經在種菜了。\n" );
	if ( !arg || ( arg != "baicai seed" && arg != "qingcai seed" ) )  
		return notify_fail( "你要種什麼？\n" );
	if ( !objectp( ob = present( arg, me ) ) )
		return notify_fail( "你沒有這種菜種。\n" );
	if ( environment(me)->query("short") != "菜地" )
		return notify_fail( "只有在菜地才能種菜。\n" );
	if ( me->is_busy() )
		return notify_fail( "你現在沒空種菜。\n" );
	if ( me->query("qi") < 30 )
		return notify_fail( "你太累了，歇一會兒再種吧。\n" );
	me->add( "qi", -30 );
	message_vision( "$N舉起鋤頭把菜地上的雜草都鋤盡了，然後笨手笨腳地把" + ob->query("name") + "種下。\n", me );		
	sort = explode( arg, " " )[0];
	destruct( ob );
	name = me->query( "id" );
	call_out( "harvest", 5, me, 5 );
	
	return 1;
}

void harvest( object me, int times )
{
	int i;
	object ob;
	string *msg=({
HIW "\n漸漸的起風了，天邊飄來一片片烏雲，集聚在菜地上空。\n看來要下雨了，趕緊搭個棚子遮一遮吧。\n" NOR,
HIC "\n晨曦微露，一羣早起覓食的鳥兒唧唧喳喳地飛來，落在菜地裏。\n快把它們趕走吧。\n" NOR,		
HIY "\n有幾株菜苗耷拉着發黃的葉子，好象得病了，得捉一捉蟲了。\n" NOR,
HIG "\n綠油油的菜苗在微風中向你點頭。\n看來這次一定是個大豐收，你不禁喜上眉梢。\n" NOR,
	});
	
	if ( times-- > 0 ) {
		i = random(4);
		write( msg[i] );
		if ( i < 3 )
			call_out( "gain", 5, me, i, times );
		else   	call_out( "harvest", 10, me, times );
	}
	else {
		ob = new( __DIR__"npc/obj/" + sort );
		ob->move( me );
		message_vision( HIG "\n$N收穫了一筐" + ob->query("name") + "！\n" NOR, me );		
		name = "";
		guarder = "";
	}
}

void gain( object me, int i, int times )
{
	string *fail_msg=({
WHT "你還沒湊齊搭棚子的材料，滂沱大雨就已傾盆而下，菜苗都泡在水裏了。\n" NOR,		
CYN "你東奔西跑地趕鳥，可是這邊趕走了幾隻，那邊又來了一羣。不一會兒菜苗就被啄光了。\n" NOR,
YEL "你一時想不出對付蟲子的辦法，只能眼睜睜看着菜苗被一點一點喫掉。\n" NOR,
	});
	string *suc_msg=({
HIW "你手腳麻利地找到繩子和木頭，三下五除二搭好棚子，再大的雨也不怕了。\n" NOR,
HIC "你紮了幾個稻草人插在菜地裏，鳥兒嚇得都飛走了。\n" NOR,
HIY "你採了一些藥草在田邊燒起來，蟲子都被燻死了。\n" NOR,		
	});

	if ( !stringp(guarder) || guarder != me->query("id") || random( me->query("kar") ) < 5 ) {
		write( fail_msg[i] );
		message_vision( WHT "\n菜苗都死光了，$N的辛苦白費了。\n" NOR, me );
		name = "";
		guarder = "";		
	} 
	else {
		write( suc_msg[i] );
		call_out( "harvest", 3, me, times );
	}
		
}

int do_guard()
{
	object me = this_player();
	
	if ( me->query("id") != name )
		return notify_fail( "你不是這個菜地的主人，不必守菜地。\n" );
	if ( me->query("id") == guarder )
		return notify_fail( "你已經在守菜地了。\n" );
	write( "你開始守菜地。\n" );
	guarder = name;
	return 1;
}
	
int valid_leave( object me, string dir )
{
	if ( guarder == me->query( "id" ) )
		return notify_fail( "你正在守菜地，不能離開。\n" );
	return 1;
}

void reset()
{
	if ( !present( name, this_object() ) )
		name = "";
	::reset();		
}	

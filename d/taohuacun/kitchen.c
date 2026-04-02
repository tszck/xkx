// /d/taohuacun/kitchen.c
// Last Modifiedy by Zeratul June 2000

#include <ansi.h>
inherit ROOM;

string  cooker = "";

void  create()
{
	int line;
	string st,ss,*str;

	set("short","廚房");
	set("long",@LONG
一間廚房，油鹽醬醋樣樣俱全，擺得滿竈頭都是。竈底火頭正大，
竈上大鐵鍋給燒得“嘶嘶”輕響，冒着清煙。牆上貼着一張油膩膩的紙
片看起來(list)象是菜單。你可以手癢起來，也想在這裏照單自己做點
可口菜餚(cook)。
LONG
);
	set("no_fight",1);
	set("no_beg",1);
	set("exits", ([
		"south" : __DIR__"road3",
	]));
	set("objects", ([
		__DIR__"npc/cooker" : 1,
	]));
	set("menus", ([]) );
	line = 1;
	while (1) {
		st = read_file( __DIR__"menu", line, 1 );
		if (!stringp(st))  break;
		st = replace_string( st, "\n", "" );
		line++;
		ss = read_file( __DIR__"menu", line, 1 );
		if (!stringp(ss))  break;
		ss = replace_string( ss, ";", "" );
		ss = replace_string( ss, "\n", "" );
		str = explode( ss, " " );
		set( "menus/" + st, str );
		line++;
	}
	set("coor/x", -90);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action( "do_list", "list" );
	add_action( "do_cook", "cook" );
}

int  do_list()
{
	int i, j;
	object ob;
	string line = "";

        line = HIC"\n≡" HIY "------------------" HIG "【俠客行一百菜譜】" HIY "------------------" HIC "≡\n" NOR;
	for ( i = 0; i < sizeof( query( "menus" ) ); i++ ) {
		ob = new( __DIR__"npc/obj/" + keys( query( "menus" ) )[i] );
		if ( objectp( ob ) )
			line += sprintf( "		" HIC "★" NOR "%s\n", ob->short() );
		line += "\n  ";
		for ( j = 0; j < sizeof ( values( query( "menus" ) )[i] ); j++ ) {
			ob = new( __DIR__"npc/obj/" + values( query( "menus" ) )[i][j] );
			if ( objectp( ob ) )
				line += sprintf( "  %s", ob->query( "name" ) );
		}
		line += "\n";
		if ( i < sizeof( query( "menus" ) ) - 1 )
			line += HIY "  ------------------------------------------------------ \n" NOR;
	}
	line += HIC "≡" HIY "------------------------------------------------------" HIC "≡\n" NOR;
	this_player()->start_more( line );

	return 1;
}


int do_cook( string arg )
{
	int i,time, sklvl;
	object ob, obj, *objs = ({}), me = this_player();
	string *str;
	string base_name,ob_name;

	sklvl = me->query_skill("cookery",1);
	if ( cooker != "" && cooker != me->query("id") )
		return notify_fail( "大師傅説道：已經有人在做菜了，你得等一會兒。\n" );
	if ( cooker == me->query("id") )
		return notify_fail( "大師傅説道：你已經在做菜了。\n" );
	if ( !stringp( arg ) ) return notify_fail("大師傅説道：你要煮什麼？\n");
	for ( i = 0; i < sizeof( query("menus") ); i ++ )
	{
		ob = new( __DIR__"npc/obj/" + keys( query( "menus" ) )[i] );
		if ( objectp( ob ) && ob->query("id") == arg )
		  	break;
		if ( objectp(ob) ) destruct(ob);
	}
	if ( i >= sizeof( query( "menus" ) ) )
	{
		if ( objectp(ob) ) destruct(ob);
		return notify_fail( "大師傅搖了搖頭，説道：你不會做這道菜。\n");
	}
	str = values( query( "menus" ) )[i];
	if ( sizeof( str ) * 20 > sklvl )
	{
		destruct(ob);
		return notify_fail( "大師傅説道：你目前的手藝做不好這道菜。\n");
	}
	for ( i = 0; i < sizeof( str ); i++ )
	{
		if ( !objectp( obj = present( str[i], me ) ) ) {
               		obj = new( __DIR__"npc/obj/" + str[i] );
               		base_name = obj->query("name");
               		ob_name   = ob->query("name");
               		if ( objectp(ob) ) destruct(ob);
               		destruct(obj);
		        return notify_fail( "大師傅笑着説道：沒有" + base_name + "怎麼做" + ob_name + "？\n" );
		}
		objs += ({obj});
	}
	for ( i = 0; i < sizeof( objs ); i++ )
	  	destruct( objs[i] );
	message_vision( "$N開始做" + ob->query( "name" ) + "。\n", me );
	cooker = me->query( "id" );
	time = 5 + random( 10 );
	me->start_busy(time);
	call_out( "do_finish", time, ob, me );
	return 1;
}

void do_finish( object ob, object me )
{
	if ( environment( me ) != this_object() )  return;
	message_vision( HIC + ob->query( "cook_msg" ) + NOR, me );
	message_vision( ob->query( "name" ) + "做成了！\n\n", me );
	ob->move( me );
	cooker = "";
	ob->set("values",me->query_skill("cookery",1));
	ob->set("make_by",me->query("id"));
	if ( me->query_skill("cookery",1) >= 150
		&& me->query_skill("cookery",1) <= 200)
	 me->improve_skill("cookery",25000);
}

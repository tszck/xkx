// Room: /city/meixiangyuan.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "媚香院");
	set("long", @LONG
院中點綴幾塊山石，西邊依牆種着一株芭蕉，一株鐵梗海棠。北邊
有一軒，上面一額題曰「媚香樓」，軒外有數十株梅花植着。山石後，
有一池。池中畜許多掛珠蛋種，細白花鱗，中蓋一亭，曰弦風。
LONG );
	set("no_fight", 1);
	set("item_desc", ([
		"north" : "依稀可以看到有女子在裏面。\n",
	]));
	set("objects", ([
		__DIR__"npc/changxiang" : 1,
	]));
	set("exits", ([ /* sizeof() == 2 */
		"west"  : __DIR__"beiliuxiang",
		"north" : __DIR__"waifang",
	]));
	set("coor/x", 41);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	string time = NATURE_D->game_time();
	string money, msg;
	if ( objectp( ob = present( "chang xiang", environment(me) ) ) 
		&& living( ob ) )
	{
		if ( dir == "north" )
		{
			if( (strsrch(time, "巳時") >= 0) || (strsrch(time, "午時") >= 0) || (strsrch(time, "醜時") >= 0) || (strsrch(time, "申時") >= 0)) 
			{
				message_vision("常翔欄住了$N説道：“現在小姐在休息呢，請以後再來吧吧。”\n", me);
				return notify_fail( "你被常翔攔住了去路。\n" );
			}
			if ( random(2) || me->query_temp( "chang_block" ) )
			{
				message_vision("常翔攔住了$N説道：“現在小姐不見客，請回吧。”\n", me);
				me->set_temp("chang_block", 1);
				remove_call_out("chang_dest");
				call_out("chang_dest", 1, me);
				return notify_fail("你被常翔攔住了去路。\n");
			}
		}
		if ( dir == "west" && me->query("lu_sing") )
		{
			money = chinese_number ( 8 + 2 * me->query("lu_sing") );
			msg = sprintf("%s%s%s%s%s", "常翔告訴你：你聽了小姐", 
				chinese_number( me->query("lu_sing") ), 
				"首曲子，一共是", money, "兩金子。\n");
			write( msg );
			return notify_fail("你被常翔攔住了去路。\n");
		}
	}
	return ::valid_leave(me, dir);
}
void chang_dest(object me)
{
	if ( me->query_temp("chang_block") )
		me->delete_temp("chang_block");
}

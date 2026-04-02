//RJQMENLOU3.C

inherit ROOM;

void create()
{
	set("short", "門樓三層");
	set("long", @LONG
這裏是一間大石室，中央擺放着石桌(zhuo)石椅(chair) ，石桌上
刻有縱橫交錯的圖案，仔細看，原來是一棋局，棋盤上兩黑(heizi)、
一白(bai zi)，正該白方落子了。卻不知對弈的棋士為何沒有下完。
LONG );
	set("exits", ([
		"down" : __DIR__"rjqmenlou2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 860);
	set("coor/z", 70);
	setup();
}

void init()
{
	add_action("do_push", "push");
	add_action("do_sit", "sit");
}

int do_sit(string arg)
{

	if ( !arg || (arg != "chair") )
		return notify_fail("你一下坐了個屁股墩。\n");	
	
	if (this_player()->query_temp("allsit")==1)
		return notify_fail("你已經座下了。\n");	
			
	this_player()->set_temp("allsit", 1);
	return notify_fail("你找了個空椅子座下，開始思考棋局。\n");	
}

int do_push(string arg)
{
	object me;
	me=this_player();
	if(me->query_temp("allsit")!=1)
	{
		message_vision("$N只覺得一陣恍惚，倒在了地上。\n", me);
		me->set_temp("hei",0);
		me->set_temp("allsit",0);		
		me->unconcious();
		return notify_fail("\n");
	}
	if ((arg!="hei zi")&&(arg!="bai zi"))
		return notify_fail("你輕輕按了一下石桌，真是一塊好玉呀！\n");
	if(me->query_temp("allsit")&&(arg=="hei zi"))
	{
		if(me->query_temp("hei")==2)
		{
			me->set_temp("hei", 0);
			return notify_fail("你輕輕按了一下黑棋子，什麼反應也沒有。\n");
		}
		else if(me->query_temp("hei")==1)
		{
			me->set_temp("hei", 2);
			return notify_fail("你輕輕按了一下黑棋子，什麼反應也沒有。\n");
		}
		else if(me->query_temp("hei")==0)
		{
			me->set_temp("hei", 1);		
			return notify_fail("你輕輕按了一下黑棋子，什麼反應也沒有。\n");
		}
	}
	if(me->query_temp("allsit")&&(arg=="bai zi"))
	{
		if(me->query_temp("hei")!=2)
				return notify_fail("你輕輕按了一下白棋子，什麼反應也沒有。\n");	
		if(me->query_temp("hei")==2)
		{
			message_vision("只見石椅猛的一沉，$N一聲慘叫，直跌到洞中去了。\n", me);
//			message_vision("石椅又迅速地恢復了原狀\n");
			me->set_temp("hei",0);
			me->set_temp("allsit",0);		
//			command("recruit " + me->query("id"));
			me->move("/d/mingjiao/rjqmidao");
			return notify_fail("\n");				
		}
	}
}			

int valid_leave(object me, string dir)
{
    me->set_temp("hei",0);
    me->set_temp("allsit",0);		
    return ::valid_leave(me, dir);
}
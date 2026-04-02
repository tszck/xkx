#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","谷後樹林");
	set("long",@LONG
樹林裏鬱鬱蔥蔥，鳥語花香，光線從樹葉的縫隙中灑
向大地，微風吹來，樹影一陣婆娑。四周全是樹，一片綠
色，在碧綠的海洋中，你漸漸地迷失了方向。
LONG
	);
	set("exits",([
		"east":__FILE__,
		"west":__FILE__,
		"north":__FILE__,
		"south":__FILE__,
	]));
	set("snake_count",5);
	set("outdoors", "jianzhong");
	set("coor/x", -400);
	set("coor/y", -420);
	set("coor/z", 0);
	setup();
}
void init()
{
 object ob1;
	object me=this_player();
	if((random(10)<2)&&(this_object()->query("snake_count")>0)&&(me->query_temp("dugu_visit")!=0)&&(!present("pusi qushe", environment(this_player()))))
	{	
		ob1=new(__DIR__"npc/pusiqushe");
		ob1->move(this_object());
		this_object()->add("snake_count",-1);
	}
}
int valid_leave(object me, string dir)
{
	int i;
	string msg;
	if(!me->query_temp("dugu_visit"))
	{
		if(dir=="north")
		{	i=(int)me->query_temp("zhongnan/tree");
			if((i>0)&&(i<10)) me->add_temp("zhongnan/tree",-1);
			if((i>9)&&(i<12)) me->add_temp("zhongnan/tree",1);
			if(i<0) me->set_temp("zhongnan/tree",0);
		}
		if(dir=="south")
		{	i=(int)me->query_temp("zhongnan/tree");
			if((i<4)||(i==14)) 
			{	me->add_temp("zhongnan/tree",1);} else me->add_temp("zhongnan/tree",-1);
			if(i<0) me->set_temp("zhongnan/tree",0);
		}
		if(dir=="east")
		{	i=(int)me->query_temp("zhongnan/tree");
			if((i>3)&&(i<10))
			{	me->add_temp("zhongnan/tree",1);} else me->add_temp("zhongnan/tree",-1);
			if(i<0) me->set_temp("zhongnan/tree",0);
		}
		if(dir=="west")
		{	i=(int)me->query_temp("zhongnan/tree");
			if((i>11)&&(i<14))
				me->add_temp("zhongnan/tree",1);
			if(i<0) me->set_temp("zhongnan/tree",0);
		}
		if (me->query_temp("zhongnan/tree") >= 15)
         	{
     	    		me->move(__DIR__"donghou");
           		me->delete_temp("zhongnan/tree");
			message("vision",me->query("name")+"一臉倦容地從樹林中鑽了出來。\n",environment(me),me);
             		return notify_fail("你走了半天，終於走出了這片樹林。\n");
         	} else
		if (me->query_temp("zhongnan/tree") < i)
		{
			message("vision",me->query("name")+"胡亂地在樹林中鑽來鑽去。\n",environment(me),me);
			msg="你走了幾步，發現你走進了樹林的更深處。\n";
		} else
		if (me->query_temp("zhongnan/tree") == i)
		{
			message("vision",me->query("name")+"鑽進了樹林，可是一會兒又走回了原地。\n",environment(me),me);
			msg="你鑽進了樹林，可是一會兒又走回了原地。\n";
		} else
		{
			message("vision",me->query("name")+"似乎胸有成竹地鑽進了樹林裏。\n",environment(me),me);
			msg="你走了幾步，發現這兒你似乎曾經走過。\n";
		}
		return notify_fail(msg);//::valid_leave(me,dir);
	}else 
	if (me->query_temp("dugu_visit")==1)
	{	if(dir=="north")
		{
			message("vision",me->query("name")+"向樹林深處走去，消失樹林之中……\n",environment(me),me);
			me->move(__DIR__"qiaobi");
			me->delete_temp("dugu_visit");
			message("vision",me->query("name")+"從樹林中走了過來。\n",environment(me),me);
			return notify_fail("你往北走了裏許，來到了一座峭壁之前。\n");
		} else
		{
			message_vision("$N在樹林裏信步而行，邊走邊欣賞風景。\n",me);
			return ::valid_leave(me,dir);
		}
	}
}
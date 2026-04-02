inherit ROOM;
int do_tao(string arg);
int do_qiao(string arg);
int do_unlock(string arg);

void create()
{
	set("short", "佛堂");
	set("long", @LONG
這是一間佛堂，牆和地板都是磚(brick)砌的。裏供着一尊如來佛像(foxiang)，
佛像前是一張供桌。桌上點着盞油燈。屋裏有些昏暗。
LONG );
        set("item_desc", ([
                "foxiang" :      
        "\n這是一尊銅像，栩栩如生，宛若真人,正笑眯眯地望着你。\n",
                "brick" : "\n很普通的石磚，一塊一塊嵌得很平整。\n",    
        ]) );
	set("exits", ([
  		"south" : __DIR__"huayuan",
  		"east"  : __DIR__"neitang",
	]));
	set("objects", ([
  		__DIR__"obj/table" : 1,
	]));
	set("getkey",0);
	set("getbook",0);
	set("coor/x", -181);
	set("coor/y", 4083);
	set("coor/z", 0);
	setup();
}

void init()
{
  add_action("do_qiao", "wa");
  add_action("do_qiao", "qiao");
  add_action("do_tao", "tao");
  add_action("do_unlock", "open");
  add_action("do_unlock", "unlock");
}


int do_tao(string arg)
{
	object me, ob;
	me = this_player();

	if( !arg || arg!="foxiang" )
		return notify_fail("你要掏什麼？\n");
	if (me->query_temp("marks/爬") )
	{
		message_vision("$N伸手在佛像耳朵裏掏了掏。\n", me);
        if ( (int)me->query_condition("get_key" ) > 0 )
		{
 //		if(me->query_temp("getkey"))
			me->receive_damage("qi",50);
			return notify_fail("你掏了半天，什麼也沒有，看來是被人取走了。\n");
		}
		switch(random(5))
		{
			case 0:		
				message_vision("$N掏了一會兒，取出一件小小物事來。\n", me);
				message_vision("$N躍下地來，對着火光一看，卻是一枚小鑰匙。\n",me);
				ob=new(__DIR__"obj/jinyaos"); 	
				me->apply_condition("get_key", 200);
 				ob->move(me);			   
				break;
			default:
				message_vision("$N伸手掏了一會兒，什麼也沒掏到。\n",me);
 				break;
		}
		return 1;
	}
	return notify_fail("你夠不着。\n");
}

int do_qiao(string arg)
{
 object me, weapon;
	me = this_player();

	if( !arg || arg!="brick" ) 
		return notify_fail("你要撬什麼？\n");
	if (me->query_temp("marks/移") )
	{
		if (!objectp(weapon = me->query_temp("weapon")))
			return notify_fail("不用傢伙恐怕不行吧！\n");
		message_vision("$N拔出兵刃，將一塊方磚撬起。\n",me);
		message("vision","登時露出一塊鐵板來，板上有個拉環，環下有個鎖孔(lock)。\n", environment(me));
		me->set_temp("marks/撬",1);
		return 1;	
	}
	else
		message_vision("\n$N胡亂撬開幾塊磚，結果什麼也沒發現。\n", this_player());
	return 1;
}

int do_unlock(string arg)
{
	object ob;

	if (!arg || arg != "lock" )
		return notify_fail("你要開什麼？\n");
	if(!this_player()->query_temp("marks/撬")) return notify_fail("鎖在哪兒啊？\n");
	if (!(ob = present("jin", this_player())))
	{  
		message_vision(
	"\n$N猛地一拉鐵環，驀聽的颼的一聲，一枝機弩從下面射了出來，正中$N胸口。\n", this_player());
		this_player()->die();
		return 1;
	}
	message_vision("$N將金鑰匙輕輕插下，只聽喀的一聲，鎖已打開。\n",this_player());
	if(query("getbook"))
		return notify_fail("你失望地發現書已經被人取走了.\n");
	message_vision("$N伸手進去，摸出一包事物，卻是個包袱，打開一看，\n"+
	"正是一部《四十二章經》。$N忍不住叫了一聲。\n",this_player());
	ob=new(__DIR__"obj/book14_5");
	set("getbook",1);
	ob->move(this_player());
	return 1;
}

int valid_leave(object me, string dir)
{
        me->delete_temp("marks/爬");
        me->delete_temp("marks/移");
        me->delete_temp("marks/撬");
        return ::valid_leave(me, dir);
}
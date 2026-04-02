// mask.c
//

inherit ITEM;
int query_autoload() {return 1;}

void create()
{
        set_name("面具", ({ "mian ju", "mask" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
	              set("long", "這似乎是一個由人皮製成的面具。\n");
		            set("no_drop", "這樣東西不能離開你。\n");
		            set("no_put",1);
		            set("no_get",1);
        }
        setup();
}

void init()
{
	add_action("do_pretend", "pretend");
}

int do_pretend(string arg)
{
	object who;
//	string str;
//	string pro;
//	int per,age;

        if (!present(this_object(), this_player()))
                return 0;

	if (!arg)
		return notify_fail("你想假裝誰？\n");
/*
	if (userp(this_player()))
	if (userp(this_player()) && !wizardp(this_player()))
		return notify_fail("什麼？\n");
*/
	if (arg == "none" || arg == "cancel") {
		this_player()->delete_temp("apply/name");
		this_player()->delete_temp("apply/id");
		this_player()->delete_temp("apply/short");
		this_player()->delete_temp("apply/long");
		this_player()->delete_temp("pretend");
	  this_player()->delete_temp("apply/come_msg");
		message_vision("$N從臉上取下了一個人皮面具。\n", this_player());
		return 1;
	}
	if(!objectp(who = present(arg, environment(this_player()))) || 
		!living(who))
		return notify_fail("你想假裝誰？\n");
	if(wizardp(who))
	   return notify_fail("你不能假裝巫師！\n");
	write("你開始假裝" + who->name() + "。\n");
//	message_vision("$N戴上了一個精功製成的人皮面具。\n", this_player());
	this_player()->set_temp("apply/name", ({who->name()}));
//	this_player()->delete_temp("apply/id");
	this_player()->set_temp("pretend",1);
	this_player()->set_temp("apply/pid", who->parse_command_id_list() );
	this_player()->set_temp("apply/short", ({who->short(1)}));
	this_player()->set_temp("apply/long", ({"/cmds/std/look"->look_living(this_player(),who,1)}));
// for go msg
	if (1)
	{
		object me = who;
		string min,mout;
		string face;
		object thing;
		string dir;
		string thing_msg;
		object env = environment(me);
		
		dir = "西邊";
	if( me->is_fighting() )
	{
		if( me->query("race") == "人類" )
		{
			if (me->query_temp("is_riding") )
			{
				mout = me->name()+"伏在" + me->query_temp("is_riding")->name() + "身上往" + dir + "落荒而逃了。\n";	       
				min = me->name()+"騎着" + me->query_temp("is_riding")->name() + "跌跌撞撞地跑了過來，模樣有些狼狽。\n";
			}
			else
			{
				mout = me->name()+"往" + dir + "落荒而逃了。\n";
				min = me->name()+"跌跌撞撞地跑了過來，模樣有些狼狽。\n";
			}
		}
		else {
			mout = me->name()+replace_string( me->query("fleeout_message"), "$d", dir );
			min  = me->name()+me->query("fleein_message");
		}
	} 
	else
	{
			if( me->query("race") == "人類" && me->query("age")>15)
			{
				face="的";
				if (me->query("gender")=="女性")
				{
					if (me->query("per") >= 30)
						face ="嬌豔絕倫" + face;
					if ((me->query("per") >= 28) &&
						(me->query("per") < 30))
						face= "清麗絕俗" + face;
					if ((me->query("per") >= 26) &&
						(me->query("per") < 28))
						face= "風情萬種" + face;
					if ((me->query("per") >= 24) &&
						(me->query("per") < 26))
						face= "容色秀麗" + face;
					if ((me->query("per") >= 21) &&
						(me->query("per") < 24))
						face= "面目姣好" + face;
					if (me->query("str") <= 16)
						face = "亭亭玉立" + face;
					if ((me->query("str") <= 20) &&
						(me->query("str") > 16))
						face= "體態輕盈"+ face;
					if ((me->query("per") < 21) &&
						(me->query("str") > 20) ||
						!userp(me))
						face = "";
				}
				else
				{
					if (me->query("per") >= 30)
						face= "玉樹臨風般" + face;
					if ((me->query("per") >= 26) &&
						(me->query("per") < 30))
						face="英俊瀟灑" + face;
					if ((me->query("per") >= 22) &&
						(me->query("per") < 26))
						face="儀表堂堂" + face;
					if (me->query("str") >=23)
						face = "身材壯碩" + face;
					if ((me->query("str") >= 20) &&
						(me->query("str") < 23))
						face= "膀大腰圓"+ face;
					if ((me->query("per")<22) &&
						(me->query("str")<20) ||
						!userp(me))
						face = "";
				}
			} else face="";
			if (objectp(thing = me->query_temp("armor/cloth")))
				thing_msg = "身着" + thing->query("name");
			else thing_msg = "全身清潔溜溜";
			if (objectp(thing = me->query_temp("weapon")))
				thing_msg += "手執" + thing->query("name");
			if( me->query("race") == "人類" )
			{
					if( env->query("outdoors") &&
						me->query_temp("is_riding"))
					{
						mout = me->name()+"騎着"+me->query_temp("is_riding")->name()+"向" + dir + "疾馳而去。\n";
						min = face + me->name() + thing_msg + "騎着"+me->query_temp("is_riding")->name()+"一路疾馳而來。\n";
					}
					else
					{
						mout = me->name() + "往" + dir + "離開。\n";
						min = face + me->name() + thing_msg + "走了過來。\n";
					}
			}
			else
			{
				mout = me->name()+replace_string( me->query("comeout_message"), "$d", dir );
				min = me->name()+me->query("comein_message");
			}
		}
	this_player()->set_temp("apply/come_msg",min);
	}
// end	
		return 1;
}
void owner_is_killed()
{
	this_player()->delete_temp("apply/come_msg");
	this_player()->delete_temp("apply/name");
	this_player()->delete_temp("pretend");
	this_player()->delete_temp("apply/pid");
	this_player()->delete_temp("apply/short");
	this_player()->delete_temp("apply/long");
        destruct(this_object());
}
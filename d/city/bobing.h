
#include <ansi.h>
inherit ROOM;

int Maxperson=100; // 最大容納人數
int minperson=2;   // 最少開始人數
//int allow_leave=1; // 不知道幹嘛 取消
int allow_start=0;  // 人數夠可以開始throw
int Max1=32;//一秀的個數
int Max2=16;//二舉的個數
int Max3=8; //四進的個數
int Max4=4; //三紅的個數
int Max5=2; //對堂的個數
int Max6=1; //狀元的個數
int Realmode=0; //是否巫師主持
object* member,leader,dutang1,dutang2,winner;
//string roomname;

int add_member(object ob);
int delete_member(object ob);
int query_member(object ob);
void do_yao(string arg);
string getit(object,int,int,string);
string checkcolor(int);
int countit( int,int,int,int,int,int,int);
int pass_token(int,int);
int startreal();
int stopreal();
int givegift();
int qianbing(object,int);
int quitgame(object me);
int fyao(string arg);
string display_item(int,int,int,int,int,int);
int is_chat_room() {return 1;}

void init()
{
	add_action("fsit","sit");
	add_action("fleave","leave");
	add_action("fleader","leader");
	add_action("fview","view");
	add_action("fyao","throw");
	add_action("startreal","start");
	add_action("stopreal","stop");
	add_action("quitgame","quit");
	add_action("quitgame","exit");
}

int fleader(string id)
{
	int i;
	object ob = this_player();

	if (wizardp(ob))
	{
		if (arrayp(member))
		{
			for (i=0;i<sizeof(member);i++)
			{
				if (member[i]->query("id")==id)
				{
					leader=member[i];
					tell_room(environment(leader), "現在輪到"+ leader->query("name")+"擲了。\n");
					return 1;
				}
			}
			notify_fail("這個人不在這裏搏餅。\n");
		}
		else notify_fail("沒人在這搏餅。\n");
	}
	return 0;
}

int startreal()
{
	int i;
	object* pl;
	object ob = this_player();
	object null;
	string roomname;
	if (!roomname=environment(ob)->query("roomname"))
    roomname=environment(ob)->query("short");
	if (wizardp(ob))
	{
		Realmode=1;
		winner=null;
		pl=users();
		message("vision", HIY + ob->query("name") + "宣佈：" + roomname + "正式開放，獎品立即兌現！\n"NOR, pl);
		if (arrayp(member))
		{
			for (i=0;i<sizeof(member);i++)
			{
				member[i]->set_temp("bobing/g1",0);       //博得bing1數量
				member[i]->set_temp("bobing/g2",0);       //博得bing2數量
				member[i]->set_temp("bobing/g3",0);       //博得bing3數量
				member[i]->set_temp("bobing/g4",0);       //博得bing4數量
				member[i]->set_temp("bobing/g5",0);       //博得bing5數量
				member[i]->set_temp("bobing/g6",0);       //博得bing6數量
				member[i]->set_temp("bobing/dest","");    //最大博到的稱號
				member[i]->set_temp("bobing/maxaward",0); //最大博到的bing*數字
				member[i]->set_temp("bobing/maxscore",0); //最大博到的分數
			}
		}
		Max1=32; //一秀的個數
		Max2=16; //二舉的個數
		Max3=8;  //四進的個數
		Max4=4;  //三紅的個數
		Max5=2;  //對堂的個數
		Max6=1;  //狀元的個數
		return 1;
	}
	return 0;
}

int stopreal()
{
	int i;
	object* pl;
	object ob = this_player();
	string roomname;
	if (!roomname=environment(ob)->query("roomname"))
    roomname=environment(ob)->query("short");

	if (wizardp(ob))
	{
		pl=users();
		if (Realmode==1)
		{
			message("vision", HIY + ob->query("name") + "宣佈：" + roomname + "兌獎已結束，下次努力了！\n"NOR, pl);
			givegift();  //分餅
			Realmode=0;
			if (arrayp(member))
			{
				for (i=0;i<sizeof(member);i++)
				{
					member[i]->set_temp("bobing/g1",0);
					member[i]->set_temp("bobing/g2",0);
					member[i]->set_temp("bobing/g3",0);
					member[i]->set_temp("bobing/g4",0);
					member[i]->set_temp("bobing/g5",0);
					member[i]->set_temp("bobing/g6",0);
					member[i]->set_temp("bobing/dest","");
					member[i]->set_temp("bobing/maxaward",0);
					member[i]->set_temp("bobing/maxscore",0);
				}
			}
		}
		return 1;
	}
	return 0;
}

int givegift()
{
	object ob;
	int i, j, num;

	if (!arrayp(member)||sizeof(member)==0)
		notify_fail("沒人在這搏餅，就別分啦。\n");
	else
	{
		for (i=0;i<sizeof(member);i++)
		{
			num=member[i]->query_temp("bobing/g1");
			if (num>0)
			{
				for (j=0;j<num;j++)
				{
					ob=new(__DIR__"obj/bing1");
					ob->set("owner",member[i]->query("id"));
					ob->move(member[i]);
				}
			}
			num=member[i]->query_temp("bobing/g2");
			if (num>0)
			{
				for (j=0;j<num;j++)
				{
					ob=new(__DIR__"obj/bing2");
					ob->set("owner",member[i]->query("id"));
					ob->move(member[i]);
				}
			}
			num=member[i]->query_temp("bobing/g3");
			if (num>0)
			{
				for (j=0;j<num;j++)
				{
					ob=new(__DIR__"obj/bing3");
					ob->set("owner",member[i]->query("id"));
					ob->move(member[i]);
				}
			}
			num=member[i]->query_temp("bobing/g4");
			if (num>0)
			{
				for (j=0;j<num;j++)
				{
					ob=new(__DIR__"obj/bing4");
					ob->set("owner",member[i]->query("id"));
					ob->move(member[i]);
				}
			}
			num=member[i]->query_temp("bobing/g5");
			if (num>0)
			{
				for (j=0;j<num;j++)
				{
					ob=new(__DIR__"obj/bing5");
					ob->set("owner",member[i]->query("id"));
					ob->move(member[i]);
				}
			}
			num=member[i]->query_temp("bobing/g6");
			if (num>0)
			{
				for (j=0;j<num;j++)
				{
					ob=new(__DIR__"obj/bing6");
					ob->set("owner",member[i]->query("id"));
					ob->move(member[i]);
				}
			}
//			member[i]->set("marks/bobing",1);
		}
		return 1;
	}
}

int pass_token(int index,int passmode)
{
	int i,passok;
	passok=0;
	if (passmode==0)
	{
		for (i=0;i<sizeof(member)-1;i++)
		{
			if (index>=sizeof(member)) index=index-sizeof(member);
			if (member[index]->query_temp("bobing_skip"))
			{
				member[index]->delete_temp("bobing_skip");
			}
			else if (interactive(member[index]) && environment(member[index])==this_object())
			{
				  passok=1;
				  leader=member[index];
				  break;
			}
			else
				delete_member(member[index]);
		}
//		if ((!passok)||(sizeof(member)<minperson))
		if ( sizeof(member)<minperson )
		{
			allow_start=0;
			tell_room(environment(leader), "陪你玩的人還不夠，等人來了吧。\n");
		}
		else if (!passok)
			fyao(" "); //除了這個人其它都在跳過中
		else tell_room(environment(leader), "現在輪到" + leader->query("name") + "擲了。\n");
		remove_call_out("check_throw");
		if (sizeof(member)>=2)
		call_out("check_throw",30,leader);
	}
}
void check_throw(object who)
{
	if (!objectp(who)) message_vision(HIC"有人臨時離開了，從下一個開始吧。\n"NOR);
	else if (!interactive(who) || environment(who)!=this_object())
		message_vision(HIC"$N暫時離開了，收回他的獎品。從下一個開始繼續博。\n"NOR,who);
	else if (Max1 == 0 && Max2 == 0 && Max3 == 0 && Max4 == 0 && Max5 == 0 && Max6 == 0)
		return;
	else
	{
		message_vision(HIC"由於$N遲遲不肯擲骰子，大家一致要求收回獎品，讓$N離開場地。\n"NOR,who);
	  delete_member(who);
	}
	pass_token(query_member(who),0);
}
int fyao(string arg)
{
	int i,j,k;
	object ob = this_player();

	i=query_member(ob);
	if (allow_start )
	{
		if (i>0)
		{
			if(ob==leader)
			{
				do_yao(arg);
				pass_token(i,0);
				return 1;
			}
			else notify_fail(HIC"還沒輪到你呢，瞎嚷嚷個啥勁呢！\n"NOR);
		}
		else notify_fail(HIC"你要先坐下來才能和大家一起搏餅。\n"NOR);
	}
	else notify_fail(HIY"現在人還不夠，悠着點吧。\n"NOR);
}

int fview()
{
	int i;
	object ob = this_player();

	if (!arrayp(member) || sizeof(member)==0)
		notify_fail("沒人在這搏餅。\n");
	else
	{
		printf(HIY"  玩家          最高獎         "HIC"一秀  "HIB"二舉  "HIG"四進  "HIR"三紅  "HIY"對堂  "HIM"狀元\n"NOR);
	        printf("┌----------------------------------------------------------------┐\n");
		for (i=0;i<sizeof(member);i++)
		{
			printf("│%-14s%-12s%6d%6d%6d%6d%6d%6d  │\n",
				member[i]->query("name"),
				member[i]->query_temp("bobing/dest"),
				member[i]->query_temp("bobing/g1"),
				member[i]->query_temp("bobing/g2"),
				member[i]->query_temp("bobing/g3"),
				member[i]->query_temp("bobing/g4"),
				member[i]->query_temp("bobing/g5"),
				member[i]->query_temp("bobing/g6"),);
		}
		printf("└----------------------------------------------------------------┘\n");
		printf("目前還有一秀餅%i塊、二舉餅%i塊、四進餅%i塊、三紅餅%i塊、對堂餅%i塊。\n", Max1, Max2, Max3, Max4, Max5);
		if (objectp(winner))
			printf("現在的狀元由%s保持。\n",winner->query("name"));
		if (objectp(leader))
			printf("現在該輪到%s擲了。\n",leader->query("name"));
		return 1;
	}
}

int fleave(string id)
{
	int i, num;
	object nil, ob = this_player();

	if (wizardp(ob))
	{
		if (arrayp(member))
		{
			for (i=0;i<sizeof(member);i++)
			{
				if (member[i]->query("id")==id) ob=member[i];
			}
			if (i==sizeof(member))
				notify_fail("這個人不在這裏搏餅。\n");
		}
		else notify_fail("沒人在這搏餅。\n");
	}
	num=query_member(ob);
	if (num)
	{
		if (leader==ob)
		{
			if (num==sizeof(member)) num=1;
			else num++;
			leader=member[num-1];
		}
	}
	else return 1;
	if (sizeof(member)>minperson)
		message_vision(HIG"$N離開了大家少了一個夥伴了！\n"NOR,ob);
	else message_vision(HIG"$N離開了大家玩不成了！\n"NOR,ob);
	Maxperson++;
	delete_member(ob);
	return 1;
}

int fsit()
{
	object ob = this_player();

	if ((int)ob->query("combat_exp") < 100)
	{
		tell_object(ob,HIY"抱歉，你就這點經驗，該不會是dummy吧？\n"NOR);
		return 1;
	}

	if (!(query_member(ob)))
	{
		if (Maxperson>0)
		{
			message_vision(HIC"$N坐下來和大家一起搏餅。\n"NOR,ob);
			Maxperson--;
			add_member(ob);
			ob->set_temp("bobing/dest","");
			ob->set_temp("bobing/g1",0);
			ob->set_temp("bobing/g2",0);
			ob->set_temp("bobing/g3",0);
			ob->set_temp("bobing/g4",0);
			ob->set_temp("bobing/g5",0);
			ob->set_temp("bobing/g6",0);
			ob->set_temp("bobing/maxscore",0);
			ob->set_temp("bobing/maxaward",0);
		}
		else tell_object(ob,HIY"這一桌滿了，你去別處看看吧。\n"NOR);
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	if (query_member(me))
		return notify_fail(HIB"你要先離開搏餅桌才能離開這裏。\n"NOR);
	return 1;
}

int quitgame(object me)
{
	if (query_member(me))
		return notify_fail(HIB"你要先離開搏餅桌才能退出遊戲。\n"NOR);
	return 1;
}

int delete_member(object ob)
{
	int i;
  object nil;
	int num;
	if (objectp(winner) && ob==winner)
	{
		winner->set_temp("bobing/g6",0);
		winner=nil;
	}
	num=query_member(ob);
	if (num)
	{
		if (leader==ob)
		{
			if (num==sizeof(member)) num=1;
			else num++;
			leader=member[num-1];
		}
	}
	else return 1;
	if (!arrayp(member)) return 0;
	for (i=0;i<sizeof(member);i++)
	{
		if (member[i]==ob)
		{
			member-=({ob});
			Max1+=ob->query_temp("bobing/g1");
			Max2+=ob->query_temp("bobing/g2");
			Max3+=ob->query_temp("bobing/g3");
			Max4+=ob->query_temp("bobing/g4");
			Max5+=ob->query_temp("bobing/g5");
			Max6+=ob->query_temp("bobing/g6");
			ob->delete_temp("bobing");
			break;
		}
	}
	member -= ({0});
}

int add_member(object ob)
{
	if (!arrayp(member))
	{
		member=({ob});
		leader=ob;
	}
	else
	{
  	member -= ({0});
		member+=({ob});
		if (sizeof(member)>=minperson)
		{
			allow_start=1;
			if (!leader) leader = ob;
			tell_room(environment(leader), "太好了，人湊夠了，可以開始玩了。\n");
			tell_room(environment(leader), leader->query("name")+"先擲吧。\n");
			remove_call_out("check_throw");
			call_out("check_throw",30,leader);
		}
	}
	return 1;
}

int query_member(object ob)
{
	int i;

	if (!arrayp(member)) return 0;
	member -= ({0});
	for (i=0;i<sizeof(member);i++)
	{
		if (member[i]==ob)
		{
			return i+1;
		}
	}
	return 0;
}

void do_yao(string arg)
{
	string *sha_msg = ({
"抓起六個骰子放在手心裏拼命搖，然後團起手來向手中吹了口氣，口中還神神叨叨地唸唸有詞：天靈靈，地靈靈……來來來，開了……\n",
"瞪着一對紅眼，大喝一聲：狀元！手中的六粒骰子往碗中一摔！\n",
"往手上吹了口氣，六粒骰子輕輕一拋．．．\n",
"故作鎮靜地將六粒骰子往碗裏一拋，不料一粒骰子從指縫中一不小心掉出碗外。完了！完了！白擲了一把！\n",
"微微一笑，六粒骰子往碗裏一滾．．．\n",
"望空作了個揖：菩薩保佑！六粒骰子戰戰兢兢地碗中一投．．．\n",
"拿着六粒骰子，抖足精神：娶老婆生孩子在此一舉！\n",
"衣袖一捲，大聲叫道：看我的！\n",
"咬牙切齒，六粒骰子往碗中上狠狠地一砸．．．\n",
"滿頭大汗，自言自語道：我不要別的，有個對堂就夠了．．\n",
"瀟灑地作了個四方揖：這把該我搶狀元了，看好了．．．\n",
});

	int t1,s1,s2,s3,s4,s5,s6,c1,c2,c3,c4,c5,c6,getaward,getscore,msgno;
	string result,dest;
	object ob = this_player();

	getscore=0;
	dest="";

//巫師作弊
	if (wizardp(ob) && arg &&
		sscanf(arg, "%d %d %d %d %d %d", s1,s2,s3,s4,s5,s6) == 6 &&
		s1 > 0 && s1 < 7 &&
		s2 > 0 && s2 < 7 &&
		s3 > 0 && s3 < 7 &&
		s4 > 0 && s4 < 7 &&
		s5 > 0 && s5 < 7 &&
		s6 > 0 && s6 < 7)
	{
		CHANNEL_D->do_channel(ob, "sys", "不好意思，就作弊一把吧。\n");
	}
	else
	{
/*		t1=random(50)+1;
// 加大對堂概率
		if (t1==25)
		{
			s1=5; s2=2; s3=6; s4=4; s5=3; s6=1;
		}
		else
		{
*/
// 正常概率
			s1=random(6)+1;
			s2=random(6)+1;
			s3=random(6)+1;
			s4=random(6)+1;
			s5=random(6)+1;
			s6=random(6)+1;
//		}
	}
//按點數統計
	c1=countit(s1,s2,s3,s4,s5,s6,1); //一的個數
	c2=countit(s1,s2,s3,s4,s5,s6,2); //二的個數
	c3=countit(s1,s2,s3,s4,s5,s6,3); //三的個數
	c4=countit(s1,s2,s3,s4,s5,s6,4); //四的個數
	c5=countit(s1,s2,s3,s4,s5,s6,5); //五的個數
	c6=countit(s1,s2,s3,s4,s5,s6,6); //六的個數

	if (c1==6||c2==6||c3==6||c4==6||c5==6||c6==6)
	{
		getaward=6;
		if (c1==6)
		{
//			dest="六  黑(一)";
//			getscore=1201;
			dest="六  幺(一)";
			getscore=1301;
		}
		else if (c2==6)
		{
			dest="六  黑(二)";
			getscore=1202;
		}
		else if (c3==6)
		{
			dest="六  黑(三)";
			getscore=1203;
		}
		else if (c5==6)
		{
			dest="六  黑(五)";
			getscore=1205;//1204
		}
		else if (c6==6)
		{
			dest="六  黑(六)";
			getscore=1206;//1205
		}
		else if (c4==6)
		{
			dest="六  紅(通喫)";
			getscore=1304;//1207
		}
	}
	else if (c4==5)
	{
		getaward=6;
		if (c1==1)
		{
			dest="五紅帶一";
			getscore=1101;//1102
		}
		else if (c2==1)
		{
			dest="五紅帶二";
			getscore=1102;//1103;
		}
		else if (c3==1)
		{
			dest="五紅帶三";
			getscore=1103;//1104;
		}
		else if (c5==1)
		{
			dest="五紅帶五";
			getscore=1105;
		}
		else if (c6==1)
		{
			dest="五紅帶六";
			getscore=1106;
		}
	}
	else if (c6==5)
	{
		getaward=6;
		if (c1==1)
		{
			dest="五主(六)帶一";
			getscore=1001;//1046;
		}
		else if (c2==1)
		{
			dest="五主(六)帶二";
			getscore=1002;//1056;
		}
		else if (c3==1)
		{
			dest="五主(六)帶三";
			getscore=1003;//1066;
		}
		else if (c4==1)
		{
			dest="五主(六)帶四";
			getscore=1004;//1076;
		}
		else if (c5==1)
		{
			dest="五主(六)帶五";
			getscore=1005;//1086;
		}
	}
	else if (c5==5)
	{
		getaward=6;
		if(c1==1)
		{
			dest="五主(五)帶一";
			getscore=1001;//1045;
		}
		else if(c2==1)
		{
			dest="五主(五)帶二";
			getscore=1002;//1055;
		}
		else if(c3==1)
		{
			dest="五主(五)帶三";
			getscore=1003;//1065;
		}
		else if(c4==1)
		{
			dest="五主(五)帶四";
			getscore=1004;//1075;
		}
		else if(c6==1)
		{
			dest="五主(五)帶六";
			getscore=1006;//1096;
		}
	}
	else if(c3==5)
	{
		getaward=6;
		if(c1==1)
		{
			dest="五主(三)帶一";
			getscore=1001;//1043;
		}
		else if(c2==1)
		{
			dest="五主(三)帶二";
			getscore=1002;//1053;
		}
		else if(c4==1)
		{
			dest="五主(三)帶四";
			getscore=1004;//1073;
		}
		else if(c5==1)
		{
			dest="五主(三 )帶五";
			getscore=1005;//1083;
		}
		else if(c6==1)
		{
			dest="五主(三)帶六";
			getscore=1006;//1093;
		}
	}
	else if(c2==5)
	{
		getaward=6;
		if(c1==1)
		{
			dest="五主(二)帶一";
			getscore=1001;//1042;
		}
		else if(c3==1)
		{
			dest="五主(二)帶三";
			getscore=1003;//1062;
		}
		else if(c4==1)
		{
			dest="五主(二)帶四";
			getscore=1004;//1072;
		}
		else if(c5==1)
		{
			dest="五主(二)帶五";
			getscore=1005;//1082;
		}
		else if(c6==1)
		{
			dest="五主(二)帶六";
			getscore=1006;//1092;
		}
	}
	else if(c1==5)
	{
		getaward=6;
		if(c2==1)
		{
			dest="五主(一)帶二";
			getscore=1002;//1051;
		}
		else if(c3==1)
		{
			dest="五主(一)帶三";
			getscore=1003;//1061;
		}
		else if(c4==1)
		{
			dest="五主(一)帶四";
			getscore=1004;//1071;
		}
		else if(c5==1)
		{
			dest="五主(一)帶五";
			getscore=1005;//1081;
		}
		else if(c6==1)
		{
			dest="五主(一)帶六";
			getscore=1006;//1091;
		}
	}
	else if (c4==4)
	{
		getaward=6;
		if((s1+s2+s3+s4+s5+s6-16)==2)
		{
			dest="狀元插金花";
	//		getscore=1206;
	// 六紅是 1304 六黑是 120 - 1205 應該比這些都大
	    getscore = 1402;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==12)
		{
			dest="狀元帶十二";
			getscore=512;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==11)
		{
			dest="狀元帶十一";
			getscore=511;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==10)
		{
			dest="狀元帶十";
			getscore=510;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==9)
		{
			dest="狀元帶九";
			getscore=509;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==8)
		{
			dest="狀元帶八";
			getscore=508;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==7)
		{
			dest="狀元帶七";
			getscore=507;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==6)
		{
			dest="狀元帶六";
			getscore=506;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==5)
		{
			dest="狀元帶五";
			getscore=505;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==4)
		{
			dest="狀元帶四";
			getscore=504;
		}
		else if((s1+s2+s3+s4+s5+s6-16)==3)
		{
			dest="狀元帶三";
			getscore=503;
		}
	}
	else if (c1==4||c2==4||c3==4||c5==4||c6==4)
	{
		getaward=3;
		if (c4==2)
		{
			getscore=302;
			dest="四進帶二舉";
		}
		else if(c4==1)
		{
			getscore=301;
			dest="四進帶一秀";
		}
		else if(c4==0)
		{
			getscore=300;
			dest="四進";
		}
	}
	else if(c4==3)
	{
		getaward=4;
		getscore=400;
		dest="三紅";
	}
	else if(c4==2)
	{
		getaward=2;
		getscore=200;
		if (c1==2)
		{
			dest="二舉插金花";
		}
		dest="二舉";
	}
	else if (c4==1)
	{
		if (c1==1&&c2==1&&c3==1&&c5==1&&c6==1)
		{
			getaward=5;
			getscore=500;
			dest="對堂";
		}
		else if (c1==2)
		{
			getaward=1;
			getscore=100;
			dest="一秀插金花";
		}
		else
		{
			getaward=1;
			getscore=100;
			dest="一秀";
		}
	}
	else
	{
		getaward=0;
		getscore=0;
		dest=NOR"………哇塞！居然什麼都不是耶！？呵呵呵呵，真同情你哦";
	}
	result=display_item(s1,s2,s3,s4,s5,s6);
	msgno = random(sizeof(sha_msg));
	if (msgno != 3) result=result+"\n居然是個"HIR+dest+NOR"？加油啊！\n";
	else
	 {
	 	result=result+"\n跳槽了，讓別人擲！\n";
	 	ob->set_temp("bobing_skip",1);//下一輪輪空
	 }
	message_vision(HIC"$N"+sha_msg[msgno]+NOR+result,ob);
	if (msgno != 3) getit(ob,getaward,getscore,dest);
}

string checkcolor(int i)
{
	if (i==1||i==4) return RED;
	else return GRN;
}

int countit(int s1,int s2,int s3,int s4,int s5,int s6,int sd)
{
	int i;

	i=0;
	if (s1==sd) i++;
	if (s2==sd) i++;
	if (s3==sd) i++;
	if (s4==sd) i++;
	if (s5==sd) i++;
	if (s6==sd) i++;
	return i;
}

string getit(object ob,int getaward,int getscore,string dest)
{
	object* play;
	string roomname;
	int i;
	if (!roomname=environment(ob)->query("roomname"))
    roomname=environment(ob)->query("short");
/*	if (getaward > (ob->query_temp("bobing/maxaward")))
	{
		ob->set_temp("bobing/maxaward",getaward );
		ob->set_temp("bobing/dest",dest);
	}
	if (getscore>(ob->query_temp("bobing/maxscore")))
		ob->set_temp("bobing/maxscore",getscore);*/
	if (getscore > (ob->query_temp("bobing/maxscore")))
	{
		ob->set_temp("bobing/maxaward",getaward );
		ob->set_temp("bobing/dest",dest);
  	ob->set_temp("bobing/maxscore",getscore);
	}
	if (getaward==1)
	{
		if (Max1<=0 )
		{
//			qianbing(ob,getaward);
				message_vision(CYN"$N搏到一秀一個，真是可惜，沒有獎品……\n"NOR, ob);
		}
		else
		{
			ob->add_temp("bobing/g1",1);
//			Max1=(Max1==0)?0:Max1-1;
       Max1 --;
			if (Realmode)
				message_vision(HIY"$N搏到一秀一個，獎一秀餅一塊！\n"NOR, ob);
			else
				message_vision(CYN"$N搏到一秀一個，真是可惜巫師不在，沒有獎品……\n"NOR, ob);
		}
	}
	if (getaward==2)
	{
		if (Max2<=0 )
		{
//			qianbing(ob,getaward);
				message_vision(CYN"$N搏到二舉一個，真是可惜，沒有獎品……\n"NOR,ob);
		}
		else
		{
//			ob->set_temp("bobing/g2",ob->query_temp("bobing/g2")+1);
//			Max2=(Max2==0)?0:Max2-1;
      ob->add_temp("bobing/g2",1);
      Max2 -- ;
			if (Realmode)
				message_vision(HIY"$N搏到二舉一個，獎二舉餅一塊！\n"NOR,ob);
			else
				message_vision(CYN"$N搏到二舉一個，真是可惜巫師不在，沒有獎品……\n"NOR,ob);
		}
	}
	if (getaward==3)
	{
		if (Max3<=0 )
		{
//			qianbing(ob,getaward);
				message_vision(CYN"$N搏到四進一個，真是可惜，沒有獎品……\n"NOR,ob);
		}
		else
		{
//			ob->set_temp("bobing/g3",ob->query_temp("bobing/g3")+1);
//			Max3=(Max3==0)?0:Max3-1;
      ob->add_temp("bobing/g3",1);
      Max3 -- ;
			if (Realmode)
				message_vision(HIY"$N搏到四進一個，獎四進餅一塊！\n"NOR,ob);
			else
				message_vision(CYN"$N搏到四進一個，真是可惜巫師不在，沒有獎品……\n"NOR,ob);
		}
    //
    if (getscore == 302) //四進帶二舉
    getit(ob,2,0,0);
    if (getscore == 301) //四進帶一秀
    getit(ob,1,0,0);
	}
	if (getaward==4)
	{
		if (Max4<=0 )
		{
			qianbing(ob,getaward);
		}
		else
		{
//			ob->set_temp("bobing/g4",ob->query_temp("bobing/g4")+1);
//			Max4=(Max4==0)?0:Max4-1;
      ob->add_temp("bobing/g4",1);
      Max4 -- ;
			if (Realmode)
				message_vision(HIY"$N搏到三紅一個，獎三紅餅一塊！\n"NOR,ob);
			else
				message_vision(CYN"$N搏到三紅一個，真是可惜巫師不在，沒有獎品……\n"NOR,ob);
		}
	}
	if (getaward==5)
	{
		if (Max5<=0 )
		{
			qianbing(ob,getaward);
		}
		else
		{
//			ob->set_temp("bobing/g5",ob->query_temp("bobing/g5")+1);
//			Max5=(Max5==0)?0:Max5-1;
      ob->add_temp("bobing/g5",1);
      Max5 -- ;
			if (Realmode)
				message_vision(HIY"$N搏到對堂一個，獎對堂餅一塊！\n"NOR,ob);
			else
				message_vision(CYN"$N搏到對堂一個，真是可惜巫師不在，沒有獎品……\n"NOR,ob);
		}
	}
	if(getaward>=6)
	{
		if(Realmode)
//		  Max6=(Max6==0)?0:Max6-1;
		  Max6=0;
		else
			message_vision(CYN"$N搏到狀元一個，真是可惜巫師不在，沒有獎品……\n"NOR,ob);
		if(!objectp(winner))
		{
			winner=ob;
			ob->set_temp("bobing/g6",1);
			play=users();
			message("vision", HIY"\n\n[搏餅最新消息]\n----------------------------------------------\n恭喜！ 恭喜！" + ob->query("name") + "搏到了" + dest + "！成為 " + roomname+"的狀元！！！\n"NOR, play);
		}
		else
		{
			if (ob!=winner &&
				getscore>winner->query_temp("bobing/maxscore"))
			{
				winner->set_temp("bobing/g6",0);
				winner=ob;
				winner->set_temp("bobing/g6",1);
				play=users();
				message("vision", HIY"\n\n[搏餅最新消息]\n----------------------------------------------\n恭喜！ 恭喜！" + ob->query("name") + "搏到了" + dest + "！成為 " + roomname+"的狀元！！！\n"NOR, play);
			}
			else
				message_vision(CYN"$N搏到狀元一個，真是可惜你的狀元沒有獎品……\n"NOR,ob);
		}
		if (getscore == 1004)//五主帶四 獎勵一個一秀
		getit(ob,1,0,0);
		if (getscore == 1304) //六紅通喫
		{
			if (arrayp(member))
			{
				for (i=0;i<sizeof(member);i++)
				{
					member[i]->set_temp("bobing/g1",0);
					member[i]->set_temp("bobing/g2",0);
					member[i]->set_temp("bobing/g3",0);
					member[i]->set_temp("bobing/g4",0);
					member[i]->set_temp("bobing/g5",0);
					member[i]->set_temp("bobing/g6",0);
				}
			}
			ob->set_temp("bobing/g1",32);
			ob->set_temp("bobing/g2",16);
			ob->set_temp("bobing/g3",8);
			ob->set_temp("bobing/g4",4);
			ob->set_temp("bobing/g5",2);
			ob->set_temp("bobing/g6",1);
	Max1=0;//一秀的個數
	Max2=0;//二舉的個數
	Max3=0; //四進的個數
	Max4=0; //三紅的個數
	Max5=0; //對堂的個數
	Max6=0; //狀元的個數
		}
		if (getscore == 1402)//狀元插金花 拿兩個對堂
		{
			getit(ob,5,0,0);
			getit(ob,5,0,0);
		}
	}
}

int qianbing(object ob,int getaward)
{
	int i, flag;

	for (i=0;i<sizeof(member);i++)
	{
		if (member[i]->query("name")==ob->query("name"))
		{
			flag=i;
			for (i=flag-1;i!=flag;i--)
			{
				if (i<0) i=sizeof(member)-1;
				switch (getaward)
				{
					case 1:
						if (member[i]->query_temp("bobing/g1"))
						{
							member[i]->add_temp("bobing/g1",-1);
							ob->add_temp("bobing/g1",1);
							message_vision(HIY "$N搏到一秀一個，搶了$n一秀餅一塊！\n"NOR,ob,member[i]);
							return 1;
						}
						break;
					case 2:
						if (member[i]->query_temp("bobing/g2"))
						{
							member[i]->add_temp("bobing/g2",-1);
							ob->add_temp("bobing/g2",1);
							message_vision(HIY "$N搏到二舉一個，搶了$n二舉餅一塊！\n"NOR,ob,member[i]);
							return 1;
						}
						break;
					case 3:
						if (member[i]->query_temp("bobing/g3"))
						{
							member[i]->add_temp("bobing/g3",-1);
							ob->add_temp("bobing/g3",1);
							message_vision(HIY "$N搏到四進一個，搶了$n四進餅一塊！\n"NOR,ob,member[i]);
							return 1;
						}
						break;
					case 4:
						if (member[i]->query_temp("bobing/g4"))
						{
							member[i]->add_temp("bobing/g4",-1);
							ob->add_temp("bobing/g4",1);
							message_vision(HIY "$N搏到三紅一個，搶了$n三紅餅一塊！\n"NOR,ob,member[i]);
							return 1;
						}
						break;
					case 5:
						if (member[i]->query_temp("bobing/g5"))
						{
							member[i]->add_temp("bobing/g5",-1);
							ob->add_temp("bobing/g5",1);
							message_vision(HIY "$N搏到對堂一個，搶了$n對堂餅一塊！\n"NOR,ob,member[i]);
							return 1;
						}
						break;
					default:
						message_vision(HIY "$N搏到一塊沒有用的餅！\n"NOR,ob);
						break;
				}
			}
			message_vision(HIY"$N搶不到一塊有用的餅！\n"NOR,ob);
			return 0;
		}
	}
	message_vision(HIY"$N居然找不到自己座位！\n"NOR,ob);
	return 0;
}

string display_item(int i1, int i2, int i3, int i4, int i5, int i6)
{
	string str;
	str = "┌------┐ ┌------┐ ┌------┐ ┌------┐ ┌------┐ ┌------┐\n";
	switch (i1)
	{
		case 1:
		case 2:
			str = str+"│　　　│";
			break;
		case 3:
			str = str+"│"GRN"●　　"NOR"│";
			break;
		case 4:
			str = str+"│"HIR"●　●"NOR"│";
			break;
		case 5:
		case 6:
			str = str+"│"GRN"●　●"NOR"│";
			break;
	}
	switch (i2)
	{
		case 1:
		case 2:
			str = str+" │　　　│";
			break;
		case 3:
			str = str+" │"GRN"●　　"NOR"│";
			break;
		case 4:
			str = str+" │"HIR"●　●"NOR"│";
			break;
		case 5:
		case 6:
			str = str+" │"GRN"●　●"NOR"│";
			break;
	}
	switch (i3)
	{
		case 1:
		case 2:
			str = str+" │　　　│";
			break;
		case 3:
			str = str+" │"GRN"●　　"NOR"│";
			break;
		case 4:
			str = str+" │"HIR"●　●"NOR"│";
			break;
		case 5:
		case 6:
			str = str+" │"GRN"●　●"NOR"│";
			break;
	}
	switch (i4)
	{
		case 1:
		case 2:
			str = str+" │　　　│";
			break;
		case 3:
			str = str+" │"GRN"●　　"NOR"│";
			break;
		case 4:
			str = str+" │"HIR"●　●"NOR"│";
			break;
		case 5:
		case 6:
			str = str+" │"GRN"●　●"NOR"│";
			break;
	}
	switch (i5)
	{
		case 1:
		case 2:
			str = str+" │　　　│";
			break;
		case 3:
			str = str+" │"GRN"●　　"NOR"│";
			break;
		case 4:
			str = str+" │"HIR"●　●"NOR"│";
			break;
		case 5:
		case 6:
			str = str+" │"GRN"●　●"NOR"│";
			break;
	}
	switch (i6)
	{
		case 1:
		case 2:
			str = str+" │　　　│\n";
			break;
		case 3:
			str = str+" │"GRN"●　　"NOR"│\n";
			break;
		case 4:
			str = str+" │"HIR"●　●"NOR"│\n";
			break;
		case 5:
		case 6:
			str = str+" │"GRN"●　●"NOR"│\n";
			break;
	}
/* 第一行. 真累! */
	switch (i1)
	{
		case 1:
			str = str+"│"HIR"　●　"NOR"│";
			break;
		case 3:
		case 5:
			str = str+"│"GRN"　●　"NOR"│";
			break;
		case 2:
		case 6:
			str = str+"│"GRN"●　●"NOR"│";
			break;
		case 4:
			str = str+"│　　　│";
			break;
	}
	switch (i2)
	{
		case 1:
			str = str+" │"HIR"　●　"NOR"│";
			break;
		case 3:
		case 5:
			str = str+" │"GRN"　●　"NOR"│";
			break;
		case 2:
		case 6:
			str = str+" │"GRN"●　●"NOR"│";
			break;
		case 4:
			str = str+" │　　　│";
			break;
	}
	switch (i3)
	{
		case 1:
			str = str+" │"HIR"　●　"NOR"│";
			break;
		case 3:
		case 5:
			str = str+" │"GRN"　●　"NOR"│";
			break;
		case 2:
		case 6:
			str = str+" │"GRN"●　●"NOR"│";
			break;
		case 4:
			str = str+" │　　　│";
			break;
	}
	switch (i4)
	{
		case 1:
			str = str+" │"HIR"　●　"NOR"│";
			break;
		case 3:
		case 5:
			str = str+" │"GRN"　●　"NOR"│";
			break;
		case 2:
		case 6:
			str = str+" │"GRN"●　●"NOR"│";
			break;
		case 4:
			str = str+" │　　　│";
			break;
	}
	switch (i5)
	{
		case 1:
			str = str+" │"HIR"　●　"NOR"│";
			break;
		case 3:
		case 5:
			str = str+" │"GRN"　●　"NOR"│";
			break;
		case 2:
		case 6:
			str = str+" │"GRN"●　●"NOR"│";
			break;
		case 4:
			str = str+" │　　　│";
			break;
	}
	switch (i6)
	{
		case 1:
			str = str+" │"HIR"　●　"NOR"│\n";
			break;
		case 3:
		case 5:
			str = str+" │"GRN"　●　"NOR"│\n";
			break;
		case 2:
		case 6:
			str = str+" │"GRN"●　●"NOR"│\n";
			break;
		case 4:
			str = str+" │　　　│\n";
			break;
	}
/* 第二行. 累死我了! */
	switch (i1)
	{
		case 1:
		case 2:
			str = str+"│　　　│";
			break;
		case 3:
			str = str+"│"GRN"　　●"NOR"│";
			break;
		case 4:
			str = str+"│"HIR"●　●"NOR"│";
			break;
		case 5:
		case 6:
			str = str+"│"GRN"●　●"NOR"│"NOR;
			break;
	}
	switch (i2)
	{
		case 1:
		case 2:
			str = str+" │　　　│";
			break;
		case 3:
			str = str+" │"GRN"　　●"NOR"│";
			break;
		case 4:
			str = str+" │"HIR"●　●"NOR"│";
			break;
		case 5:
		case 6:
			str = str+" │"GRN"●　●"NOR"│"NOR;
			break;
	}
	switch (i3)
	{
		case 1:
		case 2:
			str = str+" │　　　│";
			break;
		case 3:
			str = str+" │"GRN"　　●"NOR"│";
			break;
		case 4:
			str = str+" │"HIR"●　●"NOR"│";
			break;
		case 5:
		case 6:
			str = str+" │"GRN"●　●"NOR"│"NOR;
			break;
	}
	switch (i4)
	{
		case 1:
		case 2:
			str = str+" │　　　│";
			break;
		case 3:
			str = str+" │"GRN"　　●"NOR"│";
			break;
		case 4:
			str = str+" │"HIR"●　●"NOR"│";
			break;
		case 5:
		case 6:
			str = str+" │"GRN"●　●"NOR"│"NOR;
			break;
	}
	switch (i5)
	{
		case 1:
		case 2:
			str = str+" │　　　│";
			break;
		case 3:
			str = str+" │"GRN"　　●"NOR"│";
			break;
		case 4:
			str = str+" │"HIR"●　●"NOR"│";
			break;
		case 5:
		case 6:
			str = str+" │"GRN"●　●"NOR"│"NOR;
			break;
	}
	switch (i6)
	{
		case 1:
		case 2:
			str = str+" │　　　│\n";
			break;
		case 3:
			str = str+" │"GRN"　　●"NOR"│\n";
			break;
		case 4:
			str = str+" │"HIR"●　●"NOR"│\n";
			break;
		case 5:
		case 6:
			str = str+" │"GRN"●　●"NOR"│\n"NOR;
			break;
	}
/* 第三行. 總算搞完了! */
	str = str+"└------┘ └------┘ └------┘ └------┘ └------┘ └------┘\n";
	return str;
}
/*
中秋博餅及其規則

　

每逢中秋佳節，廈門和臺灣地區，以及海內外閩臺人士的居住地，都盛行一種“玩會餅博狀元”的習俗。該習俗源於明末清初。當時鄭成功的部將洪旭，為了緩解士兵們的思鄉之情，激勵士兵，與手下一起推敲，巧制中秋會餅，讓全體將士在中秋夜歡聚博餅。今天，廈門鼓浪嶼上還有當年博餅的雕塑。

一套中秋會餅中，共有大小不同的63塊餅。依大小順序分別為：狀元餅1塊；榜眼（對堂）餅2塊；探花（三紅）餅4塊；進士（四進）餅8塊；舉人（二舉）餅16塊，秀才（一秀）餅32塊；象徵古代四級考試。之所以有63塊餅，是因為，在古代，數字的使用是有等級之分的。81是帝王所用之數，72是千歲和親王所用之數，鄭成功封過延平王，所以用63。

博餅的玩法是：一羣人圍在一個大瓷碗邊，輪流向瓷碗內投擲骰子，一次同時投擲6顆骰子，根據骰子的排列組合，來決定投擲者應分得什麼樣的餅。一直玩到所有的餅分配完畢為止。

博餅一共有57個博規，見下表：

名稱
 排列組合
 得餅説明

狀元插金花
 四粒紅四點，二粒紅一點
 可得狀元和兩個對堂，不被追繳

紅 六 勃
 六粒紅四點
 可追繳全部的餅，但得主要請大家喫餅，只是請多少，要由得主決定

幺點六勃
 六粒紅一點
 得狀元，可被追繳，要請客

黑 六 勃
 六粒六點（二點、三點、五點）
 會餅由大家平分

五 王
 五粒紅四點
 得狀元，可被追繳

五 子
 五粒一點（二點、三點、五點、六點）
 得狀元，可被追繳

狀 元
 四粒紅四點
 得狀元，可被追繳

對 堂
 同時出現一、二、三、四、五、六點
 得對堂一個，可被追繳

三 紅
 三粒紅四點
 得三紅一個，可被追繳

四 進
 四粒一點（二點、三點、五點、六點）
 得四進一個，不被追繳

二 舉
 兩粒紅四點
 得二舉一個，不被追繳

一 秀
 一粒紅四點
 得一秀一個，不被追繳

　

　

附註
 如果沒有出現上述排列組合中的任何一種情形，則投擲者什麼也得不到；如果投擲過程中有骰子溢出瓷碗，則投擲者不僅什麼也得不到，下一輪還要輪空；

當五子得主的另1粒骰子是紅四點時，他還可以得一秀一個；

當四進得主的另2粒骰子均為紅四點時，他還可以得二舉一個；

當四進得主的另2粒骰子中只有一粒紅四點時，他還可以得一秀一個；

如果一個排列組合可以符合多種情形時，按最大者，即按排在表中最上層者，算。如兩粒紅四點，得二舉一個，而不能得一秀兩個；

在會餅全部分配完畢前，自第五個三紅得主起，後來的三紅得主均可以按順序追繳前面三紅得主的三紅餅一個；同樣，自第三個對堂得主起，後來的對堂得主，也可以按順序追繳前面對堂得主的對堂餅一個；

狀元餅的分配，則按大小來算，排在表中上層的為大，如果同時出現五王或五子，則按剩下的那個骰子的點數大小來算，點數大者勝；如果同時出現多人有四粒紅四點，則按剩下的2粒骰子的點數之和的大小來算，大者勝；如果點數相同，則先擲出者勝。


隨着社會經濟的發展，會餅中的月餅早就被其它物品所取代，比如：網球拍、牙膏、香皂、摩托車、金項鍊什麼的，只是博規還基本沒有改變。

　
*/

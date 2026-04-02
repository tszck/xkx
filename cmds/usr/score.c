// Last modified by winder 2003.9.2
// score.c
inherit F_CLEAN_UP;

#include <ansi.h>
#include <combat.h>
#include <mudlib.h>

string display_attr(int gift, int value);
string bar_string = "■■■■■■■■■■■■■■■■";
string blank_string = "□□□□□□□□□□□□□□□□";
string none_string = "                                  ";
string tribar_graph(int val, int eff, int max, string color);
string fill_blank(string type, int num);
string remove_ansi(string str)
{
	int i;
	string *color = ({ BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT, HIR, HIG, HIY, HIB, HIM, HIC, HIW, HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT, BBLK, BRED, BYEL, BBLU, BMAG, BCYN, NOR, BOLD });

	if( !str || !stringp(str) ) return 0;
	i = sizeof(color);
	while( i-- ) {
		str = replace_string(str, color[i], "");
	}
	return str;
}
string fill_blank(string type, int num)
{
	string bak;
	int i, j;

	bak="";
	i=strwidth(type);
	for (j=0; j<num-i; j++ ) bak+=" ";
	return bak;
}
int check_cc(string str);
string value_string(int value1,int value)
{
	string str;
	if(value1)
	{
		str=((int)(value1/10000)?chinese_number(value1/10000)+"億":"")+chinese_number(value1%10000)+"萬";
		if(value<1) return str+"兩黃金";
		else
			if(value<100) return str+"兩黃金"+chinese_number(value)+"文錢";
			else
				if(value<10000) return str+"兩黃金"+chinese_number(value/100)+"兩白銀"+(value%100?"又"+chinese_number(value%100)+"文錢":"");
				else return str+chinese_number(value/10000 )+"兩黃金"+((value%10000)/100 ? chinese_number((value%10000)/100)+"兩白銀":"")+((value%10000)%100 ? "又"+chinese_number((value%10000)%100)+"文錢":"");
	}
	else
	{
		if(value<1) return "";
		else
			if(value<100) return chinese_number(value)+"文錢";
			else
				if(value<10000) return chinese_number(value/100)+"兩白銀"+(value%100 ? "又"+chinese_number(value%100)+"文錢":"");
				else return chinese_number(value/10000)+"兩黃金"+((value%10000)/100 ? chinese_number((value%10000)/100)+"兩白銀":"")+((value%10000)%100 ? "又"+chinese_number((value%10000)%100)+"文錢":"");
	}
}
string display_attr(int gift, int value)
{
	if( value > gift ) return sprintf( HIY "%3d" NOR, value );
	else
		if( value < gift ) return sprintf( CYN "%3d" NOR, value );
		else return sprintf("%3d", value);
}
string tribar_graph(int val, int eff, int max, string color)
{
	return color+bar_string[0..(val*16/max)*2-1]+((eff>val) ? blank_string[(val*16/max)*2..(eff*16/max)*2-1]:"")+((max>eff) ? none_string[(eff*16/max)*2..31]:"")+NOR;
}
int check_cc(string str)
{
	int i, nn_len;
	for (nn_len=0,i=0;i<strwidth(str);i++)
	{
		if (str[i]==27)
		{
			for (;str[i]!=109;i++)
			{
				nn_len++;
			}
			nn_len++;
		}
	}
	return nn_len;
}


void create() { seteuid(ROOT_UID); }
int main(object me, string arg)
{
	string line,skill_type,master,couple,all_title,char_type;
	mapping my,pmap;
	object ob, weapon;
	int i,cc_len,attack_points,dodge_points,parry_points,balance,balance1,balance2,flag;

	seteuid(getuid());
	if(!arg) ob = me;
	else
		if (wizardp(me))
		{
			ob = present(arg, environment(me));
			if (!ob) ob = find_player(arg);
			if (!ob) ob = find_living(arg);
			if (!ob)
			{
				flag = 1;
				if (!objectp(ob=NPC_D->create_player(arg)))
					return notify_fail("沒有這個玩家。\n");
			}
			if (!ob) return notify_fail("你要察看誰的狀態？\n");
			if( !ob->is_character() || ob->is_corpse() )
				return notify_fail("你不會連"+ob->query("name") +"的狀態都想看吧？。\n");
		}else
		{
			ob = present(arg, environment(me));
			if (!ob || !me->visible(ob)) return notify_fail("你要察看誰的狀態？\n");
			if (ob != me && !(ob->query("parents") && member_array(me->query("id"), ob->query("parents"))>=0))
			return notify_fail("只有巫師能察看別人的狀態。\n");
		}
	balance = (int)ob->query("balance");
	balance1 = (int)ob->query("more_balance");
	balance2 = (int)ob->query("trade_balance");
	my = ob->query_entire_dbase();

	pmap = me->query_skill_prepare();
	if(objectp(weapon = me->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		if(sizeof(pmap)==0) skill_type="unarmed";
		else
			if(sizeof(pmap)==1) skill_type=(keys(pmap))[0];
			else
				if(sizeof(pmap)==2)
				{
					if((keys(pmap))[0]>=(keys(pmap))[1])
						skill_type = (keys(pmap))[0];
					else skill_type=(keys(pmap))[1];
				}
	attack_points = COMBAT_D->skill_power(ob,skill_type,SKILL_USAGE_ATTACK);
// 按combatd.c為標準算parry point
  if (ob->query_temp("weapon"))
  parry_points = COMBAT_D->skill_power(ob, "parry", SKILL_USAGE_DEFENSE);
  else
  parry_points = COMBAT_D->skill_power(ob, "unarmed", SKILL_USAGE_DEFENSE);
//	parry_points = COMBAT_D->skill_power(ob,skill_type,SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob,"dodge",SKILL_USAGE_DEFENSE);
	master = ob->query("family")?my["family"]["master_name"]:"目前還沒有";
	couple = mapp(my["couple"])?(my["couple"]["have_couple"]?my["couple"]["couple_name"]:"目前還沒有"):"目前還沒有";

	line = "\n┏----------"+HIR"【個人檔案】"NOR"--------┓ "+MAG"\t\t"+"    天賦"NOR"\n";

	line += sprintf("%-32s┃%s\n","┃",CYN"    悟性：["NOR+display_attr(my["int"], my["int"])+"/"+display_attr(my["int"], ob->query_int())+CYN"]     根骨：["NOR+display_attr(my["con"], my["con"])+"/"+display_attr(my["con"], ob->query_con())+CYN"] "NOR);

	line += sprintf("┃頭　　銜：　  %s%s┃%s\n", RANK_D->query_rank(ob), fill_blank(remove_ansi(RANK_D->query_rank(ob)), 16), CYN"    膂力：["NOR+display_attr(my["str"], my["str"])+"/"+display_attr(my["str"], ob->query_str())+CYN"]     身法：["NOR+display_attr(my["dex"], my["dex"])+"/"+display_attr(my["dex"], ob->query_dex())+CYN"]"NOR);

	if( wizardp(me) || (int)ob->query("age") >= 18 )
	{
		line += sprintf("%s%-16s┃%s\n", "┃中文姓名:     ",ob->name(),CYN"    耐力：["NOR+display_attr(my["sta"], my["sta"])+"/"+display_attr(my["sta"], ob->query_sta())+CYN"]     容貌：["NOR+display_attr(my["per"], my["per"])+"/"+display_attr(my["per"], ob->query_per())+CYN"]"NOR);
		line += sprintf("%s%-16s┃%s\n", "┃英文姓名:     ",ob->query("id"),CYN"    靈性：["NOR+display_attr(my["spi"], my["spi"])+"/"+display_attr(my["spi"], ob->query_spi())+CYN"]     福緣：["NOR+display_attr(my["kar"], my["kar"])+"/"+display_attr(my["kar"], ob->query_kar())+CYN"]"NOR);
		line += sprintf("%s%-16s┃%s\n", "┃性    別:     ",ob->query("gender"),CYN"    膽識：["NOR+display_attr(my["cor"], my["cor"])+"/"+display_attr(my["cor"], ob->query_cor())+CYN"]     定力：["NOR+display_attr(my["cps"], my["cps"])+"/"+display_attr(my["cps"], ob->query_cps())+CYN"]"NOR);
	}
	else
	{
		line += sprintf("%s%-16s┃%s\n", "┃中文姓名:     ",ob->name(),CYN"    耐力：["NOR"???/???"CYN"]     容貌：["NOR+"???/???"CYN"]"NOR);
		line += sprintf("%s%-16s┃%s\n", "┃英文姓名:     ",ob->query("id"),CYN"    靈性：["NOR"???/???"CYN"]     福緣：["NOR+"???/???"CYN"]"NOR);
		line += sprintf("%s%-16s┃%s\n", "┃性    別:     ",ob->query("gender"),CYN"    膽識：["NOR"???/???"CYN"]     定力：["NOR+"???/???"CYN"]"NOR);
	}

	switch (ob->query("character"))
	{
		case "1" : char_type = "冒險"; break;
		case "2" : char_type = "謹慎"; break;
		case "3" : char_type = "可人"; break;
		case "4" : char_type = "睿智"; break;
		case "5" : char_type = "堅韌"; break;
		default  : char_type = "普通"; break;
	}

	line += sprintf("%s%-16s%39s\n","┃人物性格:     ",char_type,"┗----------------------------------------┓" );
	if( ob->query("title") )
	{
		if( ob->query("degree") )
		{
			all_title = ob->query("degree")+ob->query("title");
			line += sprintf("┃稱　　謂：  　%s%s┃\n", all_title, fill_blank(remove_ansi(all_title), 58),);
		}
		else
		{
			line += sprintf("┃稱　　謂：  　%s%s┃\n", ob->query("title"), fill_blank(remove_ansi(ob->query("title")), 58),);
		}
	}

	if( ob->query("nickname") )
	{
		line += sprintf("%s%-58s", "┃你的別稱:     ",ob->query("nickname"));
		for (i=0,cc_len=check_cc(ob->query("nickname"));i<cc_len;i++)
		{
			line += sprintf("%s"," ");
		}
		line += sprintf("%s","┃\n");
	}
	if( ob->query("born") )
	{
		line += sprintf("┃你的家鄉：  　%s%26s%-28s┃\n", ob->query("born/hometown"), "你的"+(ob->query("gender")=="女性"?"老公":"老婆")+"： ",couple );
	}

	if (base_name(ob)==USER_OB)
		line += sprintf("%s%-19s%s%-28s┃\n","┃年　　齡：    ",chinese_number(ob->query("age"))+"歲"+chinese_number((ob->query("mud_age")-(ob->query("age")-ob->query("age_modify")-14)*86400)/7200+1)+"月","你的生辰： ",CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60*60) ));
	else
		line += sprintf("%s%-19s%s%-28s┃\n","┃年　　齡：    ",chinese_number(ob->query("age"))+"歲","你的生辰： ",CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60*60)));

	line += sprintf("%s%-19s%s%-26d  ┃\n", "┃你的師父：    ",master,"師門忠誠： ",ob->query("family/fealty"));

	if(ob->query("balance") || ob->query("balance1"))
	{
		line += sprintf("%12s%-58s","┃錢莊存款：    ",value_string(balance1,balance));
		for (i=0,cc_len=check_cc(value_string(balance1,balance));i<cc_len;i++)
		{
			line += sprintf("%s"," ");
		}
		line += sprintf("%s","┃\n");
	}
	if(ob->query("trade_balance"))
	{
		line += sprintf("%12s%-58s","┃商業進帳：    ",value_string(0,balance2));
		for (i=0,cc_len=check_cc(value_string(0,balance2));i<cc_len;i++)
		{
			line += sprintf("%s"," ");
		}
		line += sprintf("%s","┃\n");
	}

	if (ob->is_character())
	{
		line += sprintf("┃殺生總數：    "HIR"%-7d"NOR" 玩家：    "HIY"%-6d"NOR" 百姓：    "HIY"%-6d"NOR" 小孩：    "HIY"%-6d"NOR"┃\n", my["PKS"]+my["MKS"], my["PKS"], my["WKS"], my["WKS1"]);

		line += sprintf("┃    同門：    "HIY"%-7d"NOR" 師長：    "HIY"%-6d"NOR" 同幫：    "HIY"%-6d"NOR" 長老：    "HIY"%-6d"NOR"┃\n", my["IKS"], my["IKS1"], my["BKS"], my["BKS1"]);

		line += sprintf("┃被殺總計：    "HIR"%-7d"NOR" 橫死：    "HIR"%-6d"NOR" 叛師：    "HIY"%-6d"NOR" 開除：    "HIY"%-6d"NOR"┃\n", my["dietimes"]+my["normal_die"], my["dietimes"], my["betrayer"], my["expell"]);
	}
	if (ob->query("last_die_msg"))
		line += sprintf("┃最近死因：    %-58s┃\n",ob->query("last_die_msg"));

		line += sprintf("%s"HIW"%-19d"NOR"%s%-46s┃\n", "┃經    驗：    ", ob->query("combat_exp"), "食物： ",tribar_graph(my["food"], (ob->query("str")+10)*10,(ob->query("str")+10)*10,YEL));
		line += sprintf("%s"HIC"%-19d"NOR"%s%-46s┃\n", "┃潛    能：    ", ob->query("potential")-ob->query("learned_points"), "飲水： ", tribar_graph(my["water"], (ob->query("str")+10)*10, (ob->query("str")+10)*10,CYN));

if(ob->query("shen") >= 0)
		line += sprintf("%s"HIR"%-19d"NOR"%s%-46s┃\n", "┃正    氣：    ", ob->query("shen"), "<精>： ",tribar_graph(my["jing"], my["eff_jing"], my["max_jing"],GRN));
	else
		line += sprintf("%s"HIG"%-19d"NOR"%s%-46s┃\n", "┃戾    氣：    ", ob->query("shen"), "<精>： ",tribar_graph(my["jing"], my["eff_jing"], my["max_jing"],GRN));
	line += sprintf("%s"HIC"%-19d"NOR"%s%-45s┃\n", "┃江湖閲歷：    ", ob->query("score"), "<氣>： ", tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], HIR));
	line += sprintf("%s%-19d%s%-25d┃\n","┃江湖威望：    ", my["weiwang"], "江湖魅力：    ", my["meili"]);

	if (wizardp(me))
	{
		line += sprintf("┃攻 擊 力：    "HIR"%-18d"NOR" 躲閃能力：    "HIR"%-25d"NOR"┃\n", attack_points/100+1, dodge_points/100+1);
		line += sprintf("┃兵器傷害：    "HIY"%-18d"NOR" 招架能力：    "HIY"%-25d"NOR"┃\n", ob->query_temp("apply/damage"),parry_points/100+1  );
		line += sprintf("┃空手傷害：    "HIG"%-18d"NOR" 防護能力：    "HIG"%-25d"NOR"┃\n", ob->query_temp("apply/unarmed_damage"), ob->query_temp("apply/armor"));
		line += sprintf("┃附加攻擊：    "HIG"%-18d"NOR" 附加閃躲：    "HIG"%-25d"NOR"┃\n", ob->query_temp("apply/attack"), ob->query_temp("apply/dodge"));
	}

	line +="┗------------------------------------------------------------------------┛\n"NOR;


  line += sprintf(WHT+" %s在"+HIG+CHINESE_MUD_NAME+NOR+"裏的遊戲時間是:"+BLINK+HIY"%s \n"+NOR,ob==me?"你":ob->name(1),FINGER_D->age_string( (int)ob->query("mud_age")));

  line+=sprintf("\n");
  line+=sprintf("%s", flag?"該玩家目前不在線上。\n":"");
  write(line);
  if (flag)
		destruct(ob);
	return 1;
}

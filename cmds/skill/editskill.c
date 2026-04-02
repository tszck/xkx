// /cmds/skill/editskill.c
// Last modified by winder 2004.3.24
inherit F_CLEAN_UP;

#include <ansi.h>

#define SHUANGYIN_HAO "\""
string *valid_types = ({
	"unarmed",
	"sword",
	"blade",
});
string *banned_name=({ "  ",});
mapping spe_skill = ([
	"action" : ({" "}),
	"damage" : ({"10"}),
	"dodge" : ({"10"}),
	"parry": ({"10"}),
	"damage_type" : ({"瘀傷"}),
	"lvl" : ({"10"}),
	"skill_name" : ({"橫空出世"}),
	"skill_total_num" : ({"0"}),
	"skill_en_name" : ({" "}),
	"skill_ch_name" : ({" "}),
]);
int spe_skillnum;
string spe_skill_name;
string spe_skill_basename;
string spe_skill_help;
string oldfile;
//檢查是否是3－12位的英文id
int check_legal_id(string id);
//檢查是否是1－5箇中文字
int check_legal_name(string name);
// 檢查是否是允許的基本武功
int check_legal_basename(string name);
void skill_init_header(string skill_en_name,string skill_ch_name);
// 提示用戶輸入當前招式中文名
void get_zhaoshi_ch_name(string yn, object ob);
// 提示用戶輸入當前招式描述
void get_zhaoshi_ch_action(string yn, object ob);
// 提示用戶輸入該武功的幫助文件
void get_skill_help(string yn,object ob);
// 檢查玩家是否可以創建第skill_num招 返回skill_num
int check_skillnum_exist(object me,string skill_en_name,int skill_num);
void finish_write_skill(object ob);
// 檢查玩家是否可以改動skill_en_name這個文件
int check_owner_skill(object me,string skill_en_name);
// 從文件中讀取這個武功的中文名
string get_header_skillchname(string file);
// 從文件中讀取這個武功的基本武功名
string get_header_skillbasename(string file);
int main(object me, string arg)
{
	int skill_num,skill_num_result;
	string skill_en_name,skill_ch_name/*,myskill*/;
	string skill_base_name;

	spe_skill_basename="";
	spe_skill_name="";
	spe_skill_help="";
	spe_skillnum=0;
	oldfile="";

	seteuid(getuid());
	if(!arg)
		return notify_fail(WHT"指令格式：editskill 基本技能 武功英文名字 武功中文名字 第幾招\n"NOR);
	if( sscanf(arg, "%s %s %s %d", skill_base_name,skill_en_name,skill_ch_name,skill_num)!=4)
		return notify_fail(WHT"指令格式：editskill 基本技能 武功英文名字 武功中文名字 第幾招\n"NOR);
	skill_en_name=lower_case(skill_en_name);
	spe_skill_basename=skill_base_name;
	if(check_legal_basename(skill_base_name)==0)
		return notify_fail(RED"你輸入的基本技能不存在。\n"NOR);
	if(check_legal_id(skill_en_name)==0)
		return 1;
	spe_skill["skill_en_name"]=skill_en_name+"-"+skill_base_name+".c";
	spe_skill_name=skill_en_name+"-"+skill_base_name;
	if(check_legal_name(skill_ch_name)==0) return 1;
	spe_skill["skill_ch_name"]=skill_ch_name;
	if( skill_num!=1 && get_header_skillchname(spe_skill["skill_en_name"])!=skill_ch_name)
		return notify_fail( HIR"你輸入的中文武功名稱和所選的英文武功代號有矛盾。\n"NOR);
	if( skill_num!=1 && get_header_skillbasename(spe_skill["skill_en_name"])!=skill_base_name)
		return notify_fail( HIR"你輸入的基本技能名和所選的英文武功代號有矛盾。\n"NOR);
	if(mapp(me->query("skillmaxim")) &&
		sizeof(me->query("skillmaxim")) >3 )
		return notify_fail(HIR"你最多隻能自創三種武功。\n"NOR);
	switch(check_owner_skill(me,spe_skill["skill_en_name"]))
	{
		case 2:
			return notify_fail( HIR"此功夫已存在，無法創新。\n"NOR);
			break;
		case 0:
			break;
		case 1:
			return notify_fail( HIR"你目前只能針對這個基本技能創建一個功夫。\n"NOR);
		default:
			return notify_fail( HIR"所創功夫不對，請看幫助。\n"NOR);
	}
	if(skill_num < 1)
		return notify_fail(HIR"你需要從第一招開始創建。\n"NOR);
	if((int)me->query("combat_exp") < (skill_num)*1000000+9000000)
		return notify_fail(HIR"你的經驗還不夠，不能自創武功了。\n"NOR);
	if((int)me->query("score") < 20000)
		return notify_fail(HIR"你的江湖閱歷還不夠，不能自創武功了。\n"NOR);
	if(//(int)me->query_skill(spe_skill_name,1)!=0  &&
		(int)me->query_skill(spe_skill_name,1) < (skill_num-1)*20)
		return notify_fail( HIR"你的招式還不夠熟練，先提高一下，然後在想新招吧。\n"NOR);
	spe_skillnum=skill_num;
	skill_num_result=(check_skillnum_exist(me,spe_skill["skill_en_name"],skill_num));
	if (file_size(SKILL_D(spe_skill["skill_en_name"])))
		oldfile = read_file(SKILL_D(spe_skill["skill_en_name"]));
	switch(skill_num_result)
	{
		case -1 :
			//無法取得已經創的招式總數
			return notify_fail(HIR"你的所要創建的武功有錯，請通知巫師解決。\n"NOR);
		case 0 :
			return notify_fail( HIR"你只能創建新招或者修改最近創建的招式，請重新嘗試。\n"NOR);
		case 1 :
			// 如果創或改第一招的話 那麼一切重來
//			rm(SKILL_D(spe_skill["skill_en_name"]));
			skill_init_header(spe_skill["skill_en_name"],skill_ch_name);
			write( HIG"你現在開始創建"+skill_ch_name+"("+spe_skill_name+")"HIG"。\n"NOR);
			write( HIW"給這個武功寫一個簡介，以後會在幫助文檔中體現，換行用$代替。\n"NOR);
			input_to( (: get_skill_help :) ,this_player());
			return 1;
		default:
		//如果在原有招式上增加新的招式
			write(HIW"\r給招式起個名字（不要此時斷線，否則永遠無法再正確創建）："NOR);
			input_to( (: get_zhaoshi_ch_name :), this_player() );
			return 1;
	}
	return 0;
}
void get_skill_help(string yn,object ob)
{
	if (yn=="")
	{
		write( HIW"給這個武功寫一個簡介，將會在幫助文檔中體現。\n"NOR);
		write( HIW"換行可以用$代替\n"NOR);
		input_to( (:get_skill_help:) ,ob);
		return;
	}
	spe_skill_help = "\n\t"+yn;
	write(HIW"\r給招式起個名字（不要此時斷線，否則永遠無法再正確創建）："NOR);
	input_to( (: get_zhaoshi_ch_name :), this_player() );
	return;
}
string get_header_skillchname(string file)
{
	string result;
	string content,*list;

	content=read_file(SKILL_D(file));
	if((int)content==0) return 0;
	list = explode(content, "\n");
	if(sizeof(list) < 8) return 0;
	else
	{
		if(sscanf(list[7],"// %s",result)!=1) return 0;
		else return result;
	}
	return 0;
}
string get_header_skillbasename(string file)
{
	string result;
	string content,*list;

	content=read_file(SKILL_D(file));
	if((int)content==0) return 0;
	list = explode(content, "\n");
	if(sizeof(list) < 7) return 0;
	else
	{
		if(sscanf(list[6],"// %s",result)!=1) return 0;
		else return result;
	}
	return 0;
}
void skill_init_header(string skill_en_name,string skill_ch_name)
{
	string header, result;
	object me = this_player();
//	int i;
//	string str;

	result="";
	header="";

	header="// 這是玩家自創武功程序。\n";		//list[0]
	header+="// "+geteuid(me)+"\n";			//list[1]
	header+="// "+me->query("name")+"\n";		//list[2]
	header+="// "+me->query("title")+"\n";		//list[3]
	header+="// "+me->query("combat_exp")+"\n";	//list[4]
	header+="// "+me->query("gender")+"\n";		//list[5]
	header+="// "+spe_skill_basename+"\n";		//list[6]
	header+="// "+spe_skill["skill_ch_name"]+"\n";	//list[7]
	header+="#include <ansi.h>\n";
	header+="inherit SKILL;\n";
	header+="string type() { return \"martial\"; }\n";
	header+="string martialtype() { return \"skill\"; }\n";
	header+="string owner() {return \""+geteuid(me)+"\";}\n";
	header+="\nmapping *action = ({\n});\n";
	header+="// ZHAOSHI :0";			//注意：最後沒有用\n
	write_file(SKILL_D(skill_en_name),header,1);
}
void get_zhaoshi_ch_name(string yn, object ob)
{
	if( yn=="" )
	{
		write(HIW"\r請給招式起個名字（不要此時斷線，否則永遠無法在正確創建）："NOR);
		input_to( (: get_zhaoshi_ch_name :), ob );
		return;
	}
	if( !check_legal_name(yn) )
	{
		write(HIW"\r請給招式起個名字（不要此時斷線，否則永遠無法在正確創建）："NOR);
		input_to( (: get_zhaoshi_ch_name :), ob );
		return;
	}
	spe_skill["skill_name"]=yn;
	write(WHT"\n想象一下你和某人的戰鬥，指南：必須要有["+HIR+"你、某人、某部位"NOR+WHT"]的字樣出現！");
	write("\n如果是sword或blade請加入["HIR"武器"NOR+WHT"]字樣。以下是舉例。");
	write( HIG"\n拳法示例："NOR+WHT"你前腿踢出，後腿腳尖點地，一式「出世」，二掌直出，攻向某人的某部位\n");
	write( HIG"武器類例："NOR+WHT"你縱身一躍，手中武器一招「金光瀉地」對準的某部位斜斜刺出一劍\n"NOR);
	input_to( (: get_zhaoshi_ch_action :), ob);
}
void get_zhaoshi_ch_action(string yn, object ob)
{
	string err;
	string file;

	if( yn=="" )
	{
		write(WHT"\n想象一下你和某人的戰鬥，指南：最好要有["+HIR+"你、某人、某部位"NOR+WHT"]的字樣出現!");
		write( "\n如果是sword或blade請加入["HIR"武器"NOR+WHT"]字樣。以下是舉例。");
		write( HIG"\n拳法示例："NOR+WHT"你前腿踢出，後腿腳尖點地，一式「出世」，二掌直出，攻向某人的某部位\n");
		write( HIG"武器類例："NOR+WHT"你縱身一躍，手中武器一招「金光瀉地」對準的某部位斜斜刺出一劍\n"NOR);
		input_to( (: get_zhaoshi_ch_action :), ob );
		return;
	}
	spe_skill["action"]=yn;
	finish_write_skill(ob);
	if(spe_skillnum==1)
	{
		ob->set("skillmaxim/"+spe_skill_basename,spe_skill_name);
		ob->set_skill(spe_skill_name,1);
		ob->add("score",-20000);
		CHINESE_D->add_translate(spe_skill_name,spe_skill["skill_ch_name"]);
	}
	log_file( "CREATESKILL", sprintf("%s(%s) %s(%s): %d (%s)\n", ob->query("name"), ob->query("id"), spe_skill["skill_ch_name"], spe_skill_name, spe_skillnum, ctime(time()) ) );
	file = SKILL_D(spe_skill["skill_en_name"]);
	if (file_size(file))
	{
		if (find_object(file)) destruct(find_object(file));
		err = catch(call_other(file,"???"));
		if (stringp(err))
		{
			log_file("CREATESKILL","失敗，錯誤描述："+err);
			message("channel:sys",HIR"【系統】自創武功編輯出錯。\n"NOR,users());
			write("創建武功失敗，請聯繫當值巫師解決。\n");
			if (stringp(oldfile))
			{
				write_file(file,oldfile,1);
				call_other(file,"???");
			}
		}
	}
}
void finish_write_skill(object ob)
{
	string action, file, *list, content, *list2, header2, result;
	int before_skillnum,i;
	int flag,x,y;
	int d_e1,d_e2;//dodge上下限
	int p_e1,p_e2;//parry上下限
	int f_e1,f_e2;//force上下限
	int m_e1,m_e2;//damage上下限
	object me = this_player();

	header2="";
	result="";
	content="";
	action="";
	spe_skill["lvl"]  =20 * (spe_skillnum-1);
	spe_skill["action"]= replace_string(spe_skill["action"],"$BLK$", BLK);
	spe_skill["action"]= replace_string(spe_skill["action"],"$RED$", RED);
	spe_skill["action"]= replace_string(spe_skill["action"],"$GRN$", GRN);
	spe_skill["action"]= replace_string(spe_skill["action"],"$YEL$", YEL);
	spe_skill["action"]= replace_string(spe_skill["action"],"$BLU$", BLU);
	spe_skill["action"]= replace_string(spe_skill["action"],"$MAG$", MAG);
	spe_skill["action"]= replace_string(spe_skill["action"],"$CYN$", CYN);
	spe_skill["action"]= replace_string(spe_skill["action"],"$WHT$", WHT);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIR$", HIR);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIG$", HIG);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIY$", HIY);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIB$", HIB);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIM$", HIM);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIC$", HIC);
	spe_skill["action"]= replace_string(spe_skill["action"],"$HIW$", HIW);
	spe_skill["action"]= replace_string(spe_skill["action"],"$NOR$", NOR);
	spe_skill["action"]= replace_string(spe_skill["action"],"\"", "");
	spe_skill["action"]= replace_string(spe_skill["action"],"$","\n");
	spe_skill["action"]= replace_string(spe_skill["action"],"你","$N");
	spe_skill["action"]= replace_string(spe_skill["action"],"某人","$n");
	spe_skill["action"]= replace_string(spe_skill["action"],"某部位","$l");
	spe_skill["action"]= replace_string(spe_skill["action"],"武器","$w");
	spe_skill["action"] += NOR;
	action  = "\n([\n";
	action += "\t"+SHUANGYIN_HAO+"action"+SHUANGYIN_HAO+" : "
	        + SHUANGYIN_HAO+spe_skill["action"]+SHUANGYIN_HAO
	        + ",\n";
	action += "\t"+SHUANGYIN_HAO+"lvl"+SHUANGYIN_HAO+" : "
		+ spe_skill["lvl"]+",\n";
	action += "\t"+SHUANGYIN_HAO+"skill_name"+SHUANGYIN_HAO+" : "
		+ SHUANGYIN_HAO + spe_skill["skill_name"] + SHUANGYIN_HAO
		+ ",\n";
	action += "]),\n";
	action += "});\n";
	action += "// ZHAOSHI :"+spe_skillnum;


	file=read_file(SKILL_D(spe_skill["skill_en_name"]));
	if ((int)file==0)
	{
		write(HIR"可能出現異常了，請聯繫巫師解決。\n"NOR);
		return;
	}
	list = explode(file, "\n");
// 幫助文檔
	for(i=0;i<sizeof(list);i++)
	{
		if (list[i]=="	write(@HELP")	x=i;
		if (list[i]=="HELP")		y=i;
	}
	if (!stringp(spe_skill_help))
	{
		if (intp(x) && intp(y))
		spe_skill_help = implode(list[x+1..y-1],"\n");
		else
		spe_skill_help = this_player()->query("name")+"的自創武功。\n";
	}
	spe_skill_help = replace_string(spe_skill_help,"\"","");
	spe_skill_help = replace_string(spe_skill_help,"$","\n");
// 幫助文檔結束
/*
參考
string *spe_skill_lvl=({ "0","12","20","30","40","50","60","80","100",});
string *spe_skill_force=({ "50","80","100","130","150","180","200","220", });
string *spe_skill_unarmeddodge=({ "10","-10","-20","-30","-50","-60","-80","-90","-100", });
string *spe_skill_unarmedparry=({ "10","-10","-20","-30","-40","-50","-60","-70","-80", });
string *spe_skill_weapondodge=({ "20","10","10","5","-5","-5","-10","-10","-10", });
string *spe_skill_weaponparry=({ "20","20","10","10","5","5","5","5","5", });
*/
	if(spe_skill_basename=="unarmed")
	{
		header2=read_file(SKILL_MODEL_UNARMED);
		d_e1 = 50 - me->query("dex")/2 - 5*spe_skillnum;
		d_e2 = 50 - me->query_dex()/2  - 5*spe_skillnum;
		p_e1 = 70 - me->query("sta")/2 - 5*spe_skillnum;
		p_e2 = 70 - me->query_sta()/2  - 5*spe_skillnum;
		f_e1 = 50 + me->query("con")*3 + 10*spe_skillnum;
		f_e2 = 50 + me->query_con()*3  + 10*spe_skillnum;
		m_e1 = 0;
		m_e2 = 0;
		if (d_e1>100) d_e1=100;if (d_e1<-100) d_e1 = -100;
		if (d_e2>100) d_e2=100;if (d_e2<-100) d_e2 = -100;
		if (p_e1>100) p_e1=100;if (p_e1<-100) p_e1 = -100;
		if (p_e2>100) p_e2=100;if (p_e2<-100) p_e2 = -100;
	}
	else
	{
		d_e1 = 50 - me->query("dex")/2 - 5*spe_skillnum;
		d_e2 = 50 - me->query_dex()/2  - 5*spe_skillnum;
		p_e1 = 70 - me->query("sta")/2 - 5*spe_skillnum;
		p_e2 = 70 - me->query_sta()/2  - 5*spe_skillnum;
		f_e1 = 10 + me->query("con")*3 + 10*spe_skillnum;
		f_e2 = 10 + me->query_con()*3  + 10*spe_skillnum;
		m_e1 = 50 + me->query("str")*3 + 6*spe_skillnum;
		m_e2 = 50 + me->query_str()*3  + 6*spe_skillnum;
		if (d_e1>100) d_e1=100;if (d_e1<-100) d_e1 = -100;
		if (d_e2>100) d_e2=100;if (d_e2<-100) d_e2 = -100;
		if (p_e1>100) p_e1=100;if (p_e1<-100) p_e1 = -100;
		if (p_e2>100) p_e2=100;if (p_e2<-100) p_e2 = -100;
		if(spe_skill_basename=="sword" || spe_skill_basename=="blade")
			header2=read_file(SKILL_MODEL_WEAPON);
		else header2=read_file(SKILL_MODEL_DEFAULT);
	}

	list2 = explode(header2, "\n");
	for(i=0;i < sizeof(list2);i++)
	{
		list2[i]= replace_string(list2[i], "SKILL_EN_NAME",
			SHUANGYIN_HAO+spe_skill_name+SHUANGYIN_HAO );
		list2[i]= replace_string(list2[i], "SKILL_CH_NAME",
			SHUANGYIN_HAO+spe_skill["skill_ch_name"]+SHUANGYIN_HAO );
		list2[i]= replace_string(list2[i], "SKILL_BASE_NAME",
			SHUANGYIN_HAO+spe_skill_basename+SHUANGYIN_HAO );
		list2[i]= replace_string(list2[i], "SKILL_HELP",
			spe_skill_help);
		list2[i]= replace_string(list2[i], "D_E1",sprintf("%d",d_e1));
		list2[i]= replace_string(list2[i], "D_E2",sprintf("%d",d_e2));
		list2[i]= replace_string(list2[i], "P_E1",sprintf("%d",p_e1));
		list2[i]= replace_string(list2[i], "P_E2",sprintf("%d",p_e2));
		list2[i]= replace_string(list2[i], "F_E1",sprintf("%d",f_e1));
		list2[i]= replace_string(list2[i], "F_E2",sprintf("%d",f_e2));
		list2[i]= replace_string(list2[i], "M_E1",sprintf("%d",m_e1));
		list2[i]= replace_string(list2[i], "M_E2",sprintf("%d",m_e2));
	}
	result += implode(list2,"\n");
	for (i=sizeof(list)-1;i>0;i--)
	{
		if (!stringp(list[i])) continue;
		if (sscanf(list[i],"// ZHAOSHI :%d",before_skillnum)==1)
		{
			flag = 1;
			break;
		}
	}
	if (!flag)
	{
		write(HIR"可能出現異常了，請看幫助解決。\n"NOR);
		return;
	}
	if( before_skillnum==spe_skillnum)
	{
		flag = 0;
		for(i=i-6;i>0;i--)
		{
			if (sscanf(list[i],"// ZHAOSHI :%*d")==1)
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			write(HIR"可能出現異常情況了，請聯繫巫師解決。\n"NOR);
			return;
		}
		content = implode(list[0..i],"\n");
		content += action;
		write_file(SKILL_D(spe_skill["skill_en_name"]),content,1);
	}
	else
	{
			content = implode(list[0..i-2],"\n");
			content+="\n// ZHAOSHI :"+(string)before_skillnum;
			content+=action;
			write_file(SKILL_D(spe_skill["skill_en_name"]),content,1);
	}
	write_file(SKILL_D(spe_skill["skill_en_name"]),"\n"+result);
}
int check_legal_basename(string name)
{
	int i;
	for(i=0;i<sizeof(valid_types);i++)
		if(valid_types[i]==name) return 1;
	return 0;
}
int check_legal_id(string id)
{
	int i;
	i = strwidth(id);
	if( (strwidth(id) < 3) || (strwidth(id) > 12 ) )
	{
		write("你的武功代號必須是 3 到 12 個英文字母。\n");
		return 0;
	}
	while(i--)
		if( id[i]<'a' || id[i]>'z' )
		{
			write("你的武功代號只能用英文字母。\n");
			return 0;
		}
        return 1;
}
int check_legal_name(string name)
{
	int i;
	i = strwidth(name);
	if( (strwidth(name) < 2) || (strwidth(name) > 12 ) )
	{
		write("武功的中文名稱必須是 1 到 6 箇中文字。\n");
		return 0;
	}
	while(i--)
	{
		if( name[i]<=' ' )
		{
			write("你的武功中文名城不能用控制字元。\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) )
		{
			write("你的武功中文名要用「中文」!\n");
			return 0;
		}
	}
	if( member_array(name,banned_name)!=-1 )
	{
		write("你的武功中文名稱會造成其他人的困擾。\n");
		return 0;
	}
	return 1;
}
int check_skillnum_exist(object me,string skill_en_name,int skill_num)
{
	string file,*list;
	string playername;
	int total_zhaoshi_num;
	int flag,i;

	file=read_file(SKILL_D(spe_skill["skill_en_name"]));
	if(!file)
	{
		if(me->query("skillmaxim/"+spe_skill_basename)!=0) return 0;
		else return 1;
	}
	else list = explode(file, "\n");

	playername=geteuid(me);
	if(list[0]!="// 這是玩家自創武功程序。")
		return 0;
	if(list[1]!="// "+playername)
		return 0;
//	if(sscanf(list[sizeof(list)-1-SPE_PRA_LINES],"// ZHAOSHI :%d",total_zhaoshi_num)!=1)
//		return 0;
	for (i=sizeof(list)-1;i>0;i--)
	{
		if (!stringp(list[i])) continue;
		if (sscanf(list[i],"// ZHAOSHI :%d",total_zhaoshi_num)==1)
		{
			flag = 1;
			break;
		}
	}
	if (!flag) return -1;
	if(total_zhaoshi_num==0) return 0;
	if(total_zhaoshi_num==skill_num) return skill_num;
	if(total_zhaoshi_num+1 == skill_num) return skill_num;
	return 0;
}
int check_owner_skill(object me,string skill_en_name)
{
	string file,*list;
	string playername;

	file=read_file(SKILL_D(skill_en_name));
	if(!file)
	{
		if(me->query("skillmaxim/"+spe_skill_basename)!=0)
			return 1;
		else
			return 0;
	}
	else list = explode(file, "\n");
	playername=geteuid(me);
	if(list[1]!="// "+playername) return 2;
	if(list[0]!="// 這是玩家自創武功程序。") return 2;
	else return 0;
}

int help (object me)
{
	write(@HELP
指令格式：editskill 武功基本技能 武功英文名字 武功中文名字 第幾招
例如：editskill unarmed jueqin 絕情拳 1

    這是用來創建自己風格武功的指令，隨着經驗值的增長，可以實現的招式
越來越多，招式的威力也越來越大。每創造一種武功，必須要有兩萬點江湖閱
歷。
    玩家增加招式的熟練程度的方式是使用個專用指令：
    mylian，用practice也可以，但是難度會加大。

    由於是自己摸索招式，所以難度要大些。玩家只能修改當前的招式，對以
前的招式無法改動。所以玩家要事先規劃好總共要創幾招，邊練邊修改，以免
到時侯無法改動以前的基本招式。

    可以利用的基本功夫有：
	unarmed,
	sword,
	blade,
注意:
    招式的英文名稱後面將被加上基本技能的幾個標識，玩家要事先想好，一
旦開始創建則無法隨意改動英文名稱，如上例將會得到名爲jueqin-unarmed的
一項武功。招式描述中不要加入控制字符。玩家最多隻能創建三種高級功夫。
    招式描述中的：
    某人，你，某部位，武器帶有普遍性，將來可以用來對付各種不同敵人。

    招式的描述不要帶有對自己或對手狀態的描寫，不要不負責的亂寫。巫師
將檢查玩家所創建的功夫，如不符合規定，將被刪除。
HELP);
	return 1;
}
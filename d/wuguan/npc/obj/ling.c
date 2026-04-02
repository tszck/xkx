// d/wuguan/obj/ling.c 基本的忠誠

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("推薦令", ({"tuijian ling", "ling"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "這是從陳有德那裏得到推薦令。有了它，你可以和武館內的本門弟子\n"+
		"一起探討(tantao)武功了。\n");
		set("unit", "塊");
		set("no_get",1);
		set("no_get_from",1);
		set("no_put",1);
		set("no_give",1);
	}
}
init()
{
	add_action("do_tantao","tantao");
}
int do_tantao(string arg)
{
 	object me=this_player();
	object env=environment(me);
	object ob;
	string type,with;
  string my_fam = me->query("family/family_name");
	if (strsrch(file_name(env),"d/wuguan/") < 0)
		return notify_fail("出了武館，誰還認識你的推薦令？\n");
	if (!arg ||sscanf(arg,"%s with %s",type,with)!=2)
		return notify_fail("格式：tantao <技能> with <某人>\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("等你忙完了再來吧。\n");
	if (type!="force" && type!="dodge" && type!="parry")
		return notify_fail("你只能和別人討論基本內功、基本輕功和基本招架的內容。\n");
	if( !objectp(ob = present(with, environment(me))))
		return notify_fail("你想和誰一起討論？\n");
	if (!me->query("family"))
	 return notify_fail("你還是先加入一個門派再和別人討論問題吧。\n");
	 if (me->query("jing")<20)
	 return notify_fail("你現在太累了，休息一下再來吧。\n");
 	if ((me->query("potential") - me->query("learned_points"))< 2)
		return notify_fail("你的潛能不夠和人家一起討論問題了。\n");
	if((my_fam=="逍遙派" && ob->query("id")=="xiaoyao dizi")
	||(my_fam=="明教" && ob->query("id")=="mingjiao bangzhong")
	||(my_fam=="桃花島" && ob->query("id")=="taohuadao dizi")
	||(my_fam=="少林派" && ob->query("id")=="xiao heshang")
	||(my_fam=="神龍教" && ob->query("id")=="shenlong dizi")
	||(my_fam=="雲龍門" && ob->query("id")=="tiandihui bangzhong")
	||(my_fam=="泰山派" && ob->query("id")=="taishan dizi")
	||(my_fam=="凌霄城" && ob->query("id")=="lingxiao dizi")
	||(my_fam=="姑蘇慕容" && ob->query("id")=="murong dizi")
	||(my_fam=="星宿派" && ob->query("id")=="xingxiu dizi")
	||(my_fam=="古墓派" && ob->query("id")=="gumu dizi")
	||(my_fam=="鐵掌幫" && ob->query("id")=="tiezhang dizi")
	||(my_fam=="峨嵋派" && ob->query("id")=="xiao shitai")
	||(my_fam=="全真教" && ob->query("id")=="daotong")
	||(my_fam=="五毒教" && ob->query("id")=="wudu dizi")
	||(my_fam=="恆山派" && ob->query("id")=="hengshan nvni")
	||(my_fam=="衡山派" && ob->query("id")=="hengshan dizi")
	||(my_fam=="青城派" && ob->query("id")=="qingcheng dizi")
	||(my_fam=="紅花會" && ob->query("id")=="honghuahui bangzhong")
	||(my_fam=="雪山寺" && ob->query("id")=="xueshan dizi")
	||(my_fam=="白駝山派" && ob->query("id")=="baituo dizi")
	||(my_fam=="黑木崖" && ob->query("id")=="riyuejiao dizi")
	||(my_fam=="崑崙派" && ob->query("id")=="kunlun dizi")
	||(my_fam=="南少林派" && ob->query("id")=="nanshaolin dizi")
	||(my_fam=="華山派" && ob->query("id")=="huashan dizi")
	||(my_fam=="嵩山派" && ob->query("id")=="songshan dizi")
	||(my_fam=="武當派" && ob->query("id")=="daotong")
	||(my_fam=="大理段家" && ob->query("id")=="tianlongsi dizi")
	|| (my_fam=="丐幫" && ob->query("id")=="xiao jiaohua"))
		{
		if (me->query("teachwg/"+type)>=100)
		return notify_fail("這樣武功你已經問得差不多了，換個話題吧。\n");
		else if(me->query_skill(type,1) < me->query("teachwg/"+type) )
			return notify_fail("這樣武功你自己沒學到多少啊，怎麼和別人一起討論。\n");
		else 
			{
				tell_object(me,"你開始和"+ob->query("name")+"一起討論關於"+to_chinese(type)+"的問題。\n");
				if (random(5)<2)
					tell_object(me,"你和"+ob->query("name")+"討論了一會兒,誰也沒明白誰的意思。\n");
				else
					{
					tell_object(me,"你和"+ob->query("name")+"討論了一會兒，對"+to_chinese(type)+"的理解更深了一些。\n");
					me->add("family/fealty",3);
					write(HIW"你對自己以後在"+me->query("family/family_name")+"的發展前景更有信心了。\n"NOR);
					me->add("teachwg/"+type,1);
					me->add("learned_points",2);
					me->improve_skill(type, 2*me->query("teachwg/"+type));
			    }
			}
				me->add("jing",-(10+random(5)));
				return 1;
			}
			else
	 			return notify_fail("看起來"+ob->query("name")+"沒有和你一起討論問題的意思。\n");	
}
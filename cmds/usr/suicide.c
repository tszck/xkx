// suicide.c
inherit F_CLEAN_UP;

#include <ansi.h>



private int halt_suicide(object me);
private int slow_suicide(object me);
int sure1(string arg,object me,string skill,string pfm);
int sure2(string arg,object me,string skill,string lskill);
int scborn(object me,string arg);
varargs private void check_scborn(string passwd, object me, string skill,string etc1,string etc2);

int main(object me, string arg)
{
	object *inv;
	string *args;
	int i;

	seteuid(getuid());
	if( me->is_busy() )
		return notify_fail("你上一個動作還沒完成。\n");
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
	{
		if( userp(inv[i]))
		return notify_fail("你身上還有個大活人呢，想不開也別急呀？\n");
	}
	if( !arg )
		return notify_fail("自殺有兩種，您是要永遠死掉(-f)還是重新投胎(-r)？\n");
	args = explode(arg," ");
	if (args[0]!="-f" && args[0]!="-r")
		return notify_fail("自殺有兩種，您是要永遠死掉(-f)還是重新投胎(-r)？\n");
	if (args[0]=="-f")
	{
		write("如果您選擇永遠死掉的自殺方式，這個人物的資料就永遠刪除了，請務必\n考慮清楚，確定的話請輸入您的密碼：");
		input_to("check_password", 1, me, 1);
		return 1;
	}
	return scborn(me,implode(args[1..sizeof(args)-1]," "));
}

private void check_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("password");
	if( crypt(passwd, old_pass)!=old_pass ) {
		write("密碼錯誤！\n");
		return;
	}

	if (forever) {
		tell_object( me,
			HIR "\n\n你決定要自殺了，如果二十秒內不後悔，就真的永別了。\n\n\n" NOR);
		me->set_temp("suicide_countdown", 8);
		me->start_busy( (: slow_suicide,me :),(: halt_suicide,me :));
	}
}
private int halt_suicide(object me)
{
	tell_object(me,"你想起了泥潭裏的談笑風生，還是打消了尋死的念頭。\n");
	me->delete_temp("suicide_countdown");
	return 1;
}
private int slow_suicide(object me)
{
	object link_ob;
	int stage;
	string id;

	stage = me->query_temp("suicide_countdown");
	link_ob = me->query_temp("link_ob");
	if( !link_ob || !stage ) return 0;
	me->add_temp("suicide_countdown", -1);
	if( stage > 1 ) {
		if( (stage-1)%5 == 0 || stage < 6)
			tell_object(me, HIR "你還有 " + (stage-1)*2 + " 秒的時間可以後悔(halt)。\n" NOR);
		return 1;
	}


	log_file("static/SUICIDE",
		sprintf("%s commits a suicide on %s\n", geteuid(me), ctime(time())) );

	seteuid(getuid());
	id=geteuid(me);
	if (!id) id=getuid(me);
	link_ob->save();
	me->save();
	cp( link_ob->query_save_file() + __SAVE_EXTENSION__,sprintf(DATA_DIR "suicide/login/%c/%s"+ __SAVE_EXTENSION__, id[0], id));
	cp(      me->query_save_file() + __SAVE_EXTENSION__,sprintf(DATA_DIR "suicide/user/%c/%s" + __SAVE_EXTENSION__, id[0], id));
	rm( link_ob->query_save_file() + __SAVE_EXTENSION__ );
	rm(      me->query_save_file() + __SAVE_EXTENSION__ );
		write("好吧，永別了:)。\n");
	tell_room(environment(me), me->name() +
		"自殺了，以後你再也看不到這個人了。\n", ({me}));
  message("channel:sys",HIR"【系統】頻道精靈："+me->name()+"("+id+")自殺了。\n"NOR,users());
	destruct(link_ob);
	destruct(me);
	return 0;
}
int scborn(object me,string arg)
{
	int times;
	string skill,lskill,fskill,skill2,skill3;
	string pfm;
	int i;
	string *cant;
	mixed dir;
	string str;
//	string temp;

	notify_fail("你沒法轉生。\n");
	if (!SCBORN_D->valid_scborn(me) && me->query("id")!="mudren")
		return 0;
	times = SCBORN_D->query_scborn_times(me);
// 一轉 應該是 reborn(user,"taiji-quan","zhen"); 保存taiji-quan和pfm zhen
// 二轉 應該是 reborn(user,"taiji-quan","literate"); 保存 兩個技能
// 三轉 應該是 reborn(user,"taiji-quan","taiji-shengong"); 保存
// 四轉 應該是 reborn(user,"taiji-quan","taiji-jian");
// 五轉 應該是 reborn(user,"taiji-quan","taiji-jian","huifeng-jian");
// 六轉 應該是 reborn(user);
	switch(times)
	{
		case 0:
			if (!arg)
				return notify_fail("第一次轉生格式為：suicide -r 武功 絕招\n");
			if (sscanf(arg,"%s %s",skill,pfm)!=2)
				return notify_fail("第一次轉生格式為：suicide -r 武功 絕招\n");
			//檢查武功
			if (!me->query_skill(skill))
				return notify_fail("你並不會這個武功。\n");
			if ((SKILL_D(skill)->type())=="knowledge")
				return notify_fail("你還不能保留知識技能。\n");
			if (SKILL_D(skill)->valid_enable("force"))
				return notify_fail("你還不能保留內功。\n");
      //檢查pfm
			if (file_size(SKILL_D(skill+"/"+pfm+".c"))<0)
			{
				write(to_chinese(skill)+"並沒有"+pfm+"這個特殊用法\n");
				write("不保留武功的特殊使用嗎？(y/n)");
				input_to("sure1",me,skill,pfm);
				return 1;
			}
			if ( !me->query("perform/"+pfm) && !SCBORN_D->valid_perform(me,skill,pfm))
			{
				write("你還無法保留"+to_chinese(skill)+"的"+SKILL_D(skill+"/"+pfm)->name()+"這個特殊用法，可能是你沒學會或者這個武功不需要從掌門處學到。\n");
				write("不保留武功的特殊使用嗎？(y/n)");
				input_to("sure1",me,skill,pfm);
				return 1;
			}
			write("您選擇了轉生時保留武功："+to_chinese(skill)+"，以及相應的絕招："+SKILL_D(skill+"/"+pfm)->name()+"。\n");
			write("請輸入您的密碼以確認：");
			input_to("check_scborn",me,skill,pfm);
			break;
		case 1:
			if (!arg)
				return notify_fail("轉生格式為：suicide -r 武功 知識技能\n");
			if (sscanf(arg,"%s %s",skill,lskill)!=2)
				return notify_fail("轉生格式為：suicide -r 武功 知識技能\n");
			//檢查武功
			if (!me->query_skill(skill))
				return notify_fail("你並不會這個"+skill+"武功。\n");
			if ((SKILL_D(skill)->type())=="knowledge")
				return notify_fail("選擇的武功不能是知識技能。\n");
			if (SKILL_D(skill)->valid_enable("force"))
				return notify_fail("你不能不能保留內功。\n");
			//檢查知識技能
			if (!me->query_skill(lskill))
				return notify_fail("你並不會"+lskill+"這項技能。\n");
			if ((SKILL_D(lskill)->type())!="knowledge")
				return notify_fail(lskill+"並不是一種知識技能。\n");
			dir = get_dir("kungfu/skill/"+skill+"/");
			cant = ({});
			for (i=0;i<sizeof(dir);i++)
			{
				pfm = dir[i];
				if (dir[i][<2..<1]==".c")
					pfm = dir[i][0..<3];
				if ( !me->query("perform/"+pfm)
				&& !SCBORN_D->valid_perform(me,skill,pfm) )
					cant += ({ ("kungfu/skill/"+skill+"/"+pfm)->name() });
			}
			if (arrayp(cant))
			{
				str = "你無法保留"+to_chinese(skill)+"的"+implode(cant,"、")+"特殊用法。\n";
				str += "你不會使用這些技能，或者沒有從掌門處學得。\n";
				write(str+"不保留這部分的特殊使用嗎？(y/n)");
				input_to("sure2",me,skill,lskill);
				return 1;
			}
			write("您選擇了二次轉生時保留武功："+to_chinese(skill)+"，以及知識技能："+to_chinese(lskill)+"。\n");
			write("請輸入您的密碼以確認：");
			input_to("check_scborn",me,skill,lskill);
			break;
		case 2:
			if (!arg)
				return notify_fail("轉生格式為：suicide -r 武功 內功\n");
			if (sscanf(arg,"%s %s",skill,fskill)!=2)
				return notify_fail("轉生格式為：suicide -r 武功 內功\n");
			//檢查武功
			if (!me->query_skill(skill))
				return notify_fail("你並不會"+skill+"這個武功。\n");
			if ((SKILL_D(skill)->type())=="knowledge")
				return notify_fail("知識技能會全部保存，不需要特別指出。\n");
			if (SKILL_D(skill)->valid_enable("force"))
				return notify_fail("你只能保存一種內功。\n");
			//檢查內功
			if (!me->query_skill(fskill))
				return notify_fail("你並不會"+fskill+"這項技能。\n");
			if (!(SKILL_D(fskill)->valid_enable("force")))
				return notify_fail(fskill+"並不是一種特殊內功。\n");
			write("您選擇了三次轉生時保留武功："+to_chinese(skill)+"，以及內功技能："+to_chinese(fskill)+"。\n");
			write("請輸入您的密碼以確認：");
			input_to("check_scborn",me,skill,fskill);
			break;
		case 3:
			if (!arg)
				return notify_fail("轉生格式為：suicide -r 武功 武功\n");
			if (sscanf(arg,"%s %s",skill,skill2)!=2)
				return notify_fail("轉生格式為：suicide -r 武功 武功\n");
			//檢查武功1
			if (!me->query_skill(skill))
				return notify_fail("你並不會"+skill+"這項技能。\n");
			if ((SKILL_D(skill)->type())=="knowledge")
				return notify_fail("四轉會保存知識技能，不需要特別指出。\n");
			if (SKILL_D(skill)->valid_enable("force"))
				return notify_fail("四轉會保存所有內功，不需要特別指出。\n");
			//檢查武功2
			if (!me->query_skill(skill2))
				return notify_fail("你並不會"+skill2+"這項技能。\n");
			if ((SKILL_D(skill2)->type())=="knowledge")
				return notify_fail("四轉會保存知識技能，不需要特別指出。\n");
			if (SKILL_D(skill2)->valid_enable("force"))
				return notify_fail("四轉會保存所有內功，不需要特別指出。\n");
			write("您選擇了四次轉生時保留武功："+to_chinese(skill)+"，以及武功："+to_chinese(skill2)+"。\n");
			write("請輸入您的密碼以確認：");
			input_to("check_scborn",me,skill,skill2);
			break;
		case 4:
			if (!arg)
				return notify_fail("轉生格式為：suicide -r 武功 武功\n");
			if (sscanf(arg,"%s.%s %s",skill,skill2,skill3)!=3)
				return notify_fail("轉生格式為：suicide -r 武功 武功\n");
			//檢查武功1
			if (!me->query_skill(skill))
				return notify_fail("你並不會"+skill+"這項技能。\n");
			if ((SKILL_D(skill)->type())=="knowledge")
				return notify_fail("五轉會保存知識技能，不需要特別指出。\n");
			if (SKILL_D(skill)->valid_enable("force"))
				return notify_fail("五轉會保存所有內功，不需要特別指出。\n");
			//檢查武功2
			if (!me->query_skill(skill2))
				return notify_fail("你並不會"+skill2+"這項技能。\n");
			if ((SKILL_D(skill2)->type())=="knowledge")
				return notify_fail("五轉會保存知識技能，不需要特別指出。\n");
			if (SKILL_D(skill2)->valid_enable("force"))
				return notify_fail("五轉會保存所有內功，不需要特別指出。\n");
			//檢查武功3
			if (!me->query_skill(skill3))
				return notify_fail("你並不會"+skill3+"這項技能。\n");
			if ((SKILL_D(skill3)->type())=="knowledge")
				return notify_fail("五轉會保存知識技能，不需要特別指出。\n");
			if (SKILL_D(skill3)->valid_enable("force"))
				return notify_fail("五轉會保存所有內功，不需要特別指出。\n");
			write("您選擇了五次轉生時保留武功："+to_chinese(skill)+"、武功："+to_chinese(skill2)+" 以及武功："+to_chinese(skill3)+" 。\n");
			write("請輸入您的密碼以確認：");
			input_to("check_scborn",me,skill,skill2,skill3);
			break;
		case 5:
			write("您決定了第六次轉生。\n");
			write("請輸入您的密碼以確認：");
			input_to("check_scborn",me);
			break;
		default:
			return notify_fail("並沒有提供六轉以上轉生。\n");
	}
	return 1;
}

int sure1(string arg,object me,string skill,string pfm)
{
	if (!arg)
	{
				write("不保留武功的特殊使用嗎？(y/n)");
				input_to("sure1",me,skill,pfm);
				return 1;
	}
	if (arg[0]=='y' || arg[0]=='Y')
	{
			write("您選擇了轉生時保留武功："+to_chinese(skill)+"且不保留任何絕招。\n");
			write("請輸入您的密碼以確認：");
		input_to("check_scborn",me,skill,0);
	}
	return 1;
}
int sure2(string arg,object me,string skill,string lskill)
{
	if (!arg)
	{
				write("不保留部分特殊使用嗎？(y/n)");
				input_to("sure2",me,skill,lskill);
				return 1;
	}
	if (arg[0]=='y' || arg[0]=='Y')
	{
			write("您選擇了轉生時保留武功："+to_chinese(skill)+"且不保留部分絕招。\n");
			write("請輸入您的密碼以確認：");
		input_to("check_scborn",me,skill,lskill);
	}
	return 1;
}
varargs private void check_scborn(string passwd, object me, string skill,string etc1,string etc2)
{
	object link_ob;
	string old_pass;
	string id;
	string file;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("password");
	id = getuid(me);
	if( crypt(passwd, old_pass)!=old_pass ) {
		write("密碼錯誤！\n");
		return;
	}
	SCBORN_D->reborn(me,skill,etc1,etc2);
//	write("你可以quit了。\n");
	me->move(VOID_OB,1);
	me->save();
	seteuid(getuid());
	file = sprintf(DATA_DIR "suicide/scborn/%s"+ __SAVE_EXTENSION__,  id);
	assure_file(file);
	cp(me->query_save_file() + __SAVE_EXTENSION__ ,file);
	"/cmds/usr/exit"->savequit(me);
}
int help (object me)
{
	write(@HELP
指令格式: suicide [-f|-r]

    如果因為某種原因你不想活了，你可以選擇自殺來永遠除去資料。系統會
要求你輸入密碼以確認身份。

suicide -r : 重新投胎
suicide -f : 永遠的除去玩家資料，系統會要求你輸入密碼以確認身份。

請慎重選擇 :)

HELP);
	return 1;
}

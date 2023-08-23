package com.businessobjects.samples;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import com.crystaldecisions.sdk.occa.report.application.*;
import com.crystaldecisions.sdk.occa.report.data.IConnectionInfo;
import com.crystaldecisions.sdk.occa.report.reportsource.*;
import com.crystaldecisions.ReportViewer.ReportViewerBean;

public class HELP{
	public static void main(String[] args) {
		JFrame frame = new JFrame("Кнопка");
		frame.setSize(1920, 1280);
		frame.setLocationRelativeTo(null);
		JButton preview = new JButton("Показать отчёт");
		preview.setBackground(new Color(255, 255, 255));
		frame.getContentPane().add(preview, BorderLayout.CENTER);
		frame.setVisible(true);
		preview.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent arg0){
				showViewer();
			}
		});
	}
	
	public static void showViewer(){
		JFrame frame = new JFrame("Просмотр отчётов Crystal Reports");
		frame.setSize(1920, 1280);
		frame.setLocationRelativeTo(null);
		try{
			ReportViewerBean viewer = new ReportViewerBean();
			viewer.init();
			ReportClientDocument rcd = new ReportClientDocument();
			rcd.open("C:\\Users\\eldo5\\eclipse-workspace\\Try1000\\Sample Reports\\Report1.rpt", OpenReportOptions._openAsReadOnly);
			IConnectionInfo Info = rcd.getDatabaseController().getConnectionInfos(null).getConnectionInfo(0);
			Info.setUserName("root");
			Info.setPassword("123456");
			rcd.getDatabaseController().replaceConnection(rcd.getDatabaseController().getConnectionInfos(null).getConnectionInfo(0), Info, null, 0);
			IReportSource rs = rcd.getReportSource();
			viewer.setReportSource(rs);
			frame.getContentPane().add(viewer, BorderLayout.CENTER);
			frame.setVisible(true);
			viewer.start();
		}
		catch (Exception e){
			e.printStackTrace();
		}
	}
}

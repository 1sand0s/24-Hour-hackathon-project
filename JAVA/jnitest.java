/**
 * Copyright (C) 2015 ADITYA T 
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */
import java.awt.event.KeyAdapter;
import java.awt.Color;
import java.awt.Desktop;
import java.awt.Robot;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.KeyListener;
import java.awt.event.KeyEvent;
import java.awt.image.BufferedImage;
import java.io.*;

import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.*;
public class jnitest extends JFrame {
    static
	{
		System.loadLibrary("hello123");
		System.loadLibrary("hello321");
	}
	static char g;
	static int n;
	static jnitest t;
	static String lk;
    public native void cam();
    public native int direc();
    static BufferedImage i=null;
    static ImageIcon io;
    static File f1;
    static JPanel p=new JPanel();
    static JLabel l=new JLabel();
	public static void main(String[] args) throws IOException 
	{
		t=new jnitest();
        t.setSize(640,480);
        final project pl=new project();
        t.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f1=new File("D:/downloads/hello.jpg");
      
        try {
			i=ImageIO.read(f1);
		} catch (IOException e2) {
			// TODO Auto-generated catch block
			e2.printStackTrace();
		}
        io=new ImageIcon(i);
        l.setIcon(io);
        p.add(l);
        JMenuBar b=new JMenuBar();
        JMenu cam=new JMenu("CAM");
        JMenu direc=new JMenu("DIREC");
       
        JMenuItem cam1=new JMenuItem("CAM");
        JMenuItem direc1=new JMenuItem("direc");
        cam.add(cam1);
        direc.add(direc1);
        b.add(cam);
        b.add(direc);
        //b.add(hide);
        p.setBackground(new Color(0));
        p.add(b);
        t.setContentPane(p);
        t.setVisible(true);
        cam1.addActionListener(new ActionListener()
        {
        	public void actionPerformed(ActionEvent e)
        	{
        		t.cam();
        	}
        });
        direc1.addActionListener(new ActionListener()
        {
        	public void actionPerformed(ActionEvent e)
        	{
        		int y=t.direc();
        		if(y==5)
        		{
        			String h="http://www.facebook.com";
        			try {
						Desktop.getDesktop().browse(java.net.URI.create(h));
						pl.login("pesit","124");
						
					} catch (IOException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					} 
        		}
        		else if(y==6)
        		{
        			String h="http://www.twitter.com";
        			try {
						Desktop.getDesktop().browse(java.net.URI.create(h));
						pl.login("pesit", "125");
						
					} catch (IOException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					
        		} 
        		}
        			else if(y==7)
        			{
        				String h="http://www.instagram.com";
            			try {
    						Desktop.getDesktop().browse(java.net.URI.create(h));
    						pl.login("pesit","126");
    						
    					} catch (IOException e1) {
    						// TODO Auto-generated catch block
    						e1.printStackTrace();
    					
        			} 
        		}
        			else if(y==8)
        			{
        				String h="http://www.orkut.com";
            			try {
    						Desktop.getDesktop().browse(java.net.URI.create(h));
    						pl.login("pesit","127");
    						
    					} catch (IOException e1) {
    						// TODO Auto-generated catch block
    						e1.printStackTrace();
    					
        			} 
        			}
        	}
        });
      
	}

}

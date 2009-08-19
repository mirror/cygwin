<xsl:stylesheet version="1.0"
		xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
		xmlns="http://www.w3.org/TR/xhtml1/strict">

  <!-- call this with a result-tree-fragment -->
  <xsl:template name="maybecell-copy">
    <td>
      <xsl:variable name="body" />
      <xsl:choose>
	<xsl:when test="string-length($body)=0">-</xsl:when>
	<xsl:otherwise>
	  <xsl:copy-of select="$body"/>
	</xsl:otherwise>
      </xsl:choose>
    </td>
  </xsl:template>

  <!-- call this with a node-set or expression value -->
  <xsl:template name="maybecell">
    <td>
      <xsl:variable name="body" />
      <xsl:choose>
	<xsl:when test="string-length($body)=0">-</xsl:when>
	<xsl:otherwise>
	  <xsl:apply-templates select="$body"/>
	</xsl:otherwise>
      </xsl:choose>
    </td>
  </xsl:template>


  
  <xsl:template match="defcomponent">

    <h3>
      <a name='component-{normalize-space(translate(@name,"/","_"))}'>
	<xsl:choose>
	  <xsl:when test="../../variants">Variant: </xsl:when>
	  <xsl:otherwise>Component: </xsl:otherwise>
	</xsl:choose>
	<xsl:value-of select="@name" /> 
	<xsl:if test="@type='abstract'"> (Abstract)</xsl:if>
	</a>
    </h3>

    <xsl:choose>
      <xsl:when test="count(./*) = 0">
	<p>
	  <xsl:choose>
	    <xsl:when test="../../../defcomponent">Same as <xsl:value-of select="../../../defcomponent/attribute::name"/></xsl:when>
	    <xsl:otherwise>Unspecified</xsl:otherwise>
	  </xsl:choose>
	</p>
      </xsl:when>

      <xsl:otherwise>
	<xsl:if test="count(./defpin)">
	  <p>
	    <table cellpadding="10" cellspacing="0" border="1" width="70%">
	      <tr><th colspan="4" bgcolor="eeeeee">pins</th></tr>
	      <tr><th>name</th><th>direction</th><th>legalvalues</th><th>behaviors</th></tr>
	      <xsl:apply-templates select="./defpin"/>
	    </table>
	  </p>
	</xsl:if>

	<xsl:if test="count(./defbus)">
	  <p>
	    <table cellpadding="10" cellspacing="0" border="1" width="70%">
	      <tr><th colspan="4" bgcolor="eeeeee">buses</th></tr>
	      <tr><th>name</th><th>addresses</th><th>accesses</th><th>behaviors</th></tr>
	      <xsl:apply-templates select="./defbus"/>
	    </table>
	  </p>
	</xsl:if>
	
	<xsl:if test="count(./defattribute)">
	  <p>
	    <table cellpadding="10" cellspacing="0" border="1" width="70%">
	      <tr><th colspan="6" bgcolor="eeeeee">attributes</th></tr>
	      <tr><th>name</th><th>category</th><th>legal values</th><th>default value</th><th>behaviors</th></tr>
	      <xsl:apply-templates select="./defattribute"/>
	    </table>
	  </p>
	</xsl:if>
	
	<xsl:if test="count(./defaccessor)">
	  <p>
	    <table cellpadding="10" cellspacing="0" border="1" width="70%">
	      <tr><th colspan="3" bgcolor="eeeeee">accessors</th></tr>
	      <tr><th>name</th><th>accesses</th><th>behaviors</th></tr>
	      <xsl:apply-templates select="./defaccessor"/>
	    </table>
	  </p>
	</xsl:if>

      </xsl:otherwise>
    </xsl:choose>

    <xsl:apply-templates select="./variants"/>

  </xsl:template>
  
  <xsl:template match="defpin">
    <tr>
      <xsl:call-template name="maybecell-copy">
	<xsl:with-param name="body">
	  <a name="pin-{normalize-space(@name)}"><xsl:value-of select="@name"/></a>
	</xsl:with-param>
      </xsl:call-template>
      <xsl:call-template name="maybecell"><xsl:with-param name="body" select="@direction"/></xsl:call-template>
      <xsl:call-template name="maybecell"><xsl:with-param name="body" select="@legalvalues"/></xsl:call-template>
      <xsl:call-template name="maybecell-copy">
	<xsl:with-param name="body">
	  <a href="#behavior-{@behaviors}"><xsl:value-of select="@behaviors"/></a>
	</xsl:with-param>
      </xsl:call-template>
    </tr>
  </xsl:template>

  <xsl:template match="defbus">
    <tr>
      <xsl:call-template name="maybecell-copy">
	<xsl:with-param name="body">
	  <a name="bus-{normalize-space(@name)}"><xsl:value-of select="@name"/></a>
	</xsl:with-param>
      </xsl:call-template>
      <xsl:call-template name="maybecell"><xsl:with-param name="body" select="@addresses"/></xsl:call-template>
      <xsl:call-template name="maybecell"><xsl:with-param name="body" select="@accesses"/></xsl:call-template>
      <xsl:call-template name="maybecell-copy">
	<xsl:with-param name="body">
	  <a href="#behavior-{@behaviors}"><xsl:value-of select="@behaviors"/></a>
	</xsl:with-param>
      </xsl:call-template>
    </tr>
  </xsl:template>

  <xsl:template match="defattribute">
    <tr>
      <xsl:call-template name="maybecell-copy">
	<xsl:with-param name="body">
	  <a name="attribute-{normalize-space(@name)}"><xsl:value-of select="@name"/></a>
	</xsl:with-param>
      </xsl:call-template>
      <xsl:call-template name="maybecell"><xsl:with-param name="body" select="@category"/></xsl:call-template>
      <xsl:call-template name="maybecell"><xsl:with-param name="body" select="@legalvalues"/></xsl:call-template>
      <xsl:call-template name="maybecell"><xsl:with-param name="body" select="@defaultvalue"/></xsl:call-template>
      <xsl:call-template name="maybecell-copy">
	<xsl:with-param name="body">
	  <a href="#behavior-{@behaviors}"><xsl:value-of select="@behaviors"/></a>
	</xsl:with-param>
      </xsl:call-template>
    </tr>
  </xsl:template>

  <xsl:template match="defaccessor">
    <tr>
      <xsl:call-template name="maybecell-copy">
	<xsl:with-param name="body">
	  <a name="accessor-{normalize-space(@name)}"><xsl:value-of select="@name"/></a>
	</xsl:with-param>
      </xsl:call-template>
      <xsl:call-template name="maybecell"><xsl:with-param name="body" select="@accesses"/></xsl:call-template>
      <xsl:call-template name="maybecell-copy">
	<xsl:with-param name="body">
	  <a href="#behavior-{@behaviors}"><xsl:value-of select="@behaviors"/></a>
	</xsl:with-param>
      </xsl:call-template>
    </tr>
  </xsl:template>


  <xsl:template match="defcomplib">
    <xsl:variable name="cname">
      <xsl:value-of select="./defcomponent/attribute::name" />
    </xsl:variable>

    <xsl:variable name="title">
      <xsl:value-of select="./defcomponent/attribute::name" />
      <xsl:if test="count(./defcomponent/variants//defcomponent) > 1">
	(<xsl:for-each select="./defcomponent/variants//defcomponent">
	  <xsl:text> </xsl:text>
	  <xsl:value-of select="./@name" /> 
	  <xsl:text> </xsl:text>
	</xsl:for-each>)
      </xsl:if>
    </xsl:variable>

    <html>
      <head>
	<title><xsl:copy-of select="$title" /></title>	
      </head>
      <body bgcolor="ffffff">
	<h1><xsl:value-of select="$cname" /> (<xsl:value-of select="@lib" /> :: <xsl:value-of select="@dlsym" />)</h1>

	<h2>Synopsis:</h2>
	<xsl:apply-templates select="./synop"/>

	<hr noshade="true"/>
	<h2>Functionality:</h2>
	<xsl:apply-templates select="./func"/>

	<hr noshade="true"/>
	<h2>Environment:</h2>
	<xsl:apply-templates select="./env"/>

	<hr noshade="true"/>
	<h2>Component Reference:</h2>
	<xsl:apply-templates select="./defcomponent"/>

	<xsl:if test="./refs">
	  <hr noshade="true"/>	
	  <h2>References:</h2>	
	  <xsl:apply-templates select="./refs"/>
	</xsl:if>

      </body>
    </html>
  </xsl:template>  <!-- end defcomplib -->
  

  <xsl:template match="pin|bus|attribute|accessor">
    <a href="#{local-name()}-{normalize-space(string(.))}"><tt><xsl:apply-templates/></tt></a>
  </xsl:template>

  <xsl:template match="component">
    <a href='#component-{normalize-space(translate(string(.),"/","_"))}'><tt><xsl:apply-templates/></tt></a>
  </xsl:template>

  <xsl:template match="complib">
    <a href="{string(.)}.html"><tt><xsl:apply-templates/></tt></a>
  </xsl:template>

  <xsl:template match="name">"<tt><xsl:apply-templates/></tt>"</xsl:template>
    
  <xsl:template match="table">
    <table border="1" cellspacing="0" cellpadding="5">
      <xsl:apply-templates />
    </table>
  </xsl:template>

  <xsl:template match="th">
    <th align="left">
      <xsl:apply-templates />
    </th>
  </xsl:template>


  <xsl:template match="em|tt|p|li|tr|td">
    <xsl:element name="{local-name()}">
      <xsl:apply-templates />
    </xsl:element>
  </xsl:template>

  <xsl:template match="code">
    <tt><pre><xsl:apply-templates /></pre></tt>
  </xsl:template>

  <xsl:template match="title">
    <font size="+1"><U><xsl:apply-templates /></U></font> <br />
  </xsl:template>

  <xsl:template match="a">
    <xsl:variable name="link">
      <xsl:choose>
	<xsl:when test="@type='url'"><xsl:value-of select="@href" /></xsl:when>
	<xsl:when test="@type='techdoc'">
	  http://sources.redhat.com/sid/techdoc.cgi?<xsl:value-of select="@href" />
	</xsl:when>
	<xsl:when test="@type='component'">
	  http://sources.redhat.com/sid/component.cgi?<xsl:value-of select="@href" />
	</xsl:when>	
      </xsl:choose>
    </xsl:variable>
    <a href="{$link}"><xsl:apply-templates /></a>
  </xsl:template>
  
  <xsl:template match="synop|env|refs|behavior|convention|modelling">
    <p><xsl:apply-templates /></p>
  </xsl:template>

  <xsl:template match="func">
    <h3>Modelling:</h3>
    <xsl:apply-templates select="./modelling"/>

    <xsl:if test="count(./behavior) != 0">
      <p>
	<table cellspacing="0" cellpadding="10" border="1" width="70%">
	  <tr><th colspan="2" bgcolor="eeeeee">Behaviors</th></tr>
	  <xsl:for-each select="./behavior">
	    <tr>
	      <td align="right" valign="top"><a name="behavior-{@name}"><xsl:value-of select="@name"/></a></td>
	      <td align="left" valign="top"><xsl:apply-templates/></td>
	    </tr>
	  </xsl:for-each>
	</table>
      </p>
    </xsl:if>

    <xsl:if test="count(./convention) != 0">
      <p>
	<table cellpadding="10" cellspacing="0" border="1" width="70%">
	  <tr><th colspan="3" bgcolor="eeeeee">SID Conventions</th></tr>
	  <xsl:for-each select="./convention">
	    <tr>
	      <td align="right" valign="top"><a name="convention-{@name}"><xsl:value-of select="@name"/></a></td>
	      <td align="left" valign="top">
		<xsl:if test="@supported='false'">not </xsl:if> supported
	      </td>
	      <xsl:call-template name="maybecell"><xsl:with-param name="body" select="./*"/></xsl:call-template>
	    </tr>
	  </xsl:for-each>
	</table>
      </p>
    </xsl:if>
  </xsl:template>


  <xsl:template match="ul|ol">
    <xsl:apply-templates select="./title"/>    
    <xsl:element name="{local-name()}">
      <xsl:apply-templates select="./li"/>
    </xsl:element>
  </xsl:template>
    

</xsl:stylesheet>

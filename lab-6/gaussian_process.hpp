
// Code generated by stanc v2.26.1
#include <stan/model/model_header.hpp>
namespace gaussian_process_model_namespace {


inline void validate_positive_index(const char* var_name, const char* expr,
                                    int val) {
  if (val < 1) {
    std::stringstream msg;
    msg << "Found dimension size less than one in simplex declaration"
        << "; variable=" << var_name << "; dimension size expression=" << expr
        << "; expression value=" << val;
    std::string msg_str(msg.str());
    throw std::invalid_argument(msg_str.c_str());
  }
}

inline void validate_unit_vector_index(const char* var_name, const char* expr,
                                       int val) {
  if (val <= 1) {
    std::stringstream msg;
    if (val == 1) {
      msg << "Found dimension size one in unit vector declaration."
          << " One-dimensional unit vector is discrete"
          << " but the target distribution must be continuous."
          << " variable=" << var_name << "; dimension size expression=" << expr;
    } else {
      msg << "Found dimension size less than one in unit vector declaration"
          << "; variable=" << var_name << "; dimension size expression=" << expr
          << "; expression value=" << val;
    }
    std::string msg_str(msg.str());
    throw std::invalid_argument(msg_str.c_str());
  }
}


using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using std::pow;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::model_base_crtp;
using stan::model::rvalue;
using stan::model::cons_list;
using stan::model::index_uni;
using stan::model::index_max;
using stan::model::index_min;
using stan::model::index_min_max;
using stan::model::index_multi;
using stan::model::index_omni;
using stan::model::nil_index_list;
using namespace stan::math;
using stan::math::pow; 

stan::math::profile_map profiles__;
static int current_statement__= 0;
static const std::vector<string> locations_array__ = {" (found before start of program)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 19, column 1 to column 27)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 23, column 1 to column 47)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 32, column 1 to column 58)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 27, column 1 to column 23)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 28, column 1 to column 48)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 2, column 1 to column 24)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 3, column 16 to column 25)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 3, column 1 to column 27)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 5, column 1 to column 20)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 6, column 12 to column 17)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 6, column 1 to column 19)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 7, column 44 to column 49)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 7, column 1 to column 51)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 8, column 1 to column 19)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 9, column 1 to column 21)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 10, column 1 to column 21)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 14, column 8 to column 17)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 14, column 19 to column 28)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 14, column 1 to column 116)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 15, column 8 to column 17)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 15, column 19 to column 28)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 15, column 1 to column 62)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 19, column 8 to column 17)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 23, column 8 to column 17)",
                                                      " (in '/Users/dominikwozniak/study/data_analytics/lab-6/gaussian_process.stan', line 32, column 16 to column 25)"};



class gaussian_process_model final : public model_base_crtp<gaussian_process_model> {

 private:
  int N_predict;
  std::vector<double> x_predict;
  int N_obs;
  std::vector<double> y_obs;
  std::vector<int> observed_idx;
  double rho;
  double alpha;
  double sigma;
  Eigen::Matrix<double, -1, -1> cov;
  Eigen::Matrix<double, -1, -1> L_cov;
 
 public:
  ~gaussian_process_model() { }
  
  inline std::string model_name() const final { return "gaussian_process_model"; }

  inline std::vector<std::string> model_compile_info() const noexcept {
    return std::vector<std::string>{"stanc_version = stanc3 v2.26.1", "stancflags = "};
  }
  
  
  gaussian_process_model(stan::io::var_context& context__,
                         unsigned int random_seed__ = 0,
                         std::ostream* pstream__ = nullptr) : model_base_crtp(0) {
    using local_scalar_t__ = double ;
    boost::ecuyer1988 base_rng__ = 
        stan::services::util::create_rng(random_seed__, 0);
    (void) base_rng__;  // suppress unused var warning
    static const char* function__ = "gaussian_process_model_namespace::gaussian_process_model";
    (void) function__;  // suppress unused var warning
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void) DUMMY_VAR__;  // suppress unused var warning
    
    try {
      int pos__;
      pos__ = std::numeric_limits<int>::min();
      
      pos__ = 1;
      current_statement__ = 6;
      context__.validate_dims("data initialization","N_predict","int",
          context__.to_vec());
      N_predict = std::numeric_limits<int>::min();
      
      current_statement__ = 6;
      N_predict = context__.vals_i("N_predict")[(1 - 1)];
      current_statement__ = 6;
      current_statement__ = 6;
      check_greater_or_equal(function__, "N_predict", N_predict, 1);
      current_statement__ = 7;
      validate_non_negative_index("x_predict", "N_predict", N_predict);
      current_statement__ = 8;
      context__.validate_dims("data initialization","x_predict","double",
          context__.to_vec(N_predict));
      x_predict = std::vector<double>(N_predict, std::numeric_limits<double>::quiet_NaN());
      
      current_statement__ = 8;
      assign(x_predict, nil_index_list(), context__.vals_r("x_predict"),
        "assigning variable x_predict");
      current_statement__ = 9;
      context__.validate_dims("data initialization","N_obs","int",
          context__.to_vec());
      N_obs = std::numeric_limits<int>::min();
      
      current_statement__ = 9;
      N_obs = context__.vals_i("N_obs")[(1 - 1)];
      current_statement__ = 9;
      current_statement__ = 9;
      check_greater_or_equal(function__, "N_obs", N_obs, 1);
      current_statement__ = 10;
      validate_non_negative_index("y_obs", "N_obs", N_obs);
      current_statement__ = 11;
      context__.validate_dims("data initialization","y_obs","double",
          context__.to_vec(N_obs));
      y_obs = std::vector<double>(N_obs, std::numeric_limits<double>::quiet_NaN());
      
      current_statement__ = 11;
      assign(y_obs, nil_index_list(), context__.vals_r("y_obs"),
        "assigning variable y_obs");
      current_statement__ = 12;
      validate_non_negative_index("observed_idx", "N_obs", N_obs);
      current_statement__ = 13;
      context__.validate_dims("data initialization","observed_idx","int",
          context__.to_vec(N_obs));
      observed_idx = std::vector<int>(N_obs, std::numeric_limits<int>::min());
      
      current_statement__ = 13;
      assign(observed_idx, nil_index_list(),
        context__.vals_i("observed_idx"), "assigning variable observed_idx");
      current_statement__ = 13;
      for (int sym1__ = 1; sym1__ <= N_obs; ++sym1__) {
        current_statement__ = 13;
        current_statement__ = 13;
        check_greater_or_equal(function__, "observed_idx[sym1__]",
                               observed_idx[(sym1__ - 1)], 1);}
      current_statement__ = 13;
      for (int sym1__ = 1; sym1__ <= N_obs; ++sym1__) {
        current_statement__ = 13;
        current_statement__ = 13;
        check_less_or_equal(function__, "observed_idx[sym1__]",
                            observed_idx[(sym1__ - 1)], N_predict);}
      current_statement__ = 14;
      context__.validate_dims("data initialization","rho","double",
          context__.to_vec());
      rho = std::numeric_limits<double>::quiet_NaN();
      
      current_statement__ = 14;
      rho = context__.vals_r("rho")[(1 - 1)];
      current_statement__ = 14;
      current_statement__ = 14;
      check_greater_or_equal(function__, "rho", rho, 0);
      current_statement__ = 15;
      context__.validate_dims("data initialization","alpha","double",
          context__.to_vec());
      alpha = std::numeric_limits<double>::quiet_NaN();
      
      current_statement__ = 15;
      alpha = context__.vals_r("alpha")[(1 - 1)];
      current_statement__ = 15;
      current_statement__ = 15;
      check_greater_or_equal(function__, "alpha", alpha, 0);
      current_statement__ = 16;
      context__.validate_dims("data initialization","sigma","double",
          context__.to_vec());
      sigma = std::numeric_limits<double>::quiet_NaN();
      
      current_statement__ = 16;
      sigma = context__.vals_r("sigma")[(1 - 1)];
      current_statement__ = 16;
      current_statement__ = 16;
      check_greater_or_equal(function__, "sigma", sigma, 0);
      current_statement__ = 17;
      validate_non_negative_index("cov", "N_predict", N_predict);
      current_statement__ = 18;
      validate_non_negative_index("cov", "N_predict", N_predict);
      current_statement__ = 19;
      cov = Eigen::Matrix<double, -1, -1>(N_predict, N_predict);
      stan::math::fill(cov, std::numeric_limits<double>::quiet_NaN());
      
      current_statement__ = 19;
      assign(cov, nil_index_list(),
        add(cov_exp_quad(x_predict, alpha, rho),
          diag_matrix(rep_vector(1e-10, N_predict))),
        "assigning variable cov");
      current_statement__ = 20;
      validate_non_negative_index("L_cov", "N_predict", N_predict);
      current_statement__ = 21;
      validate_non_negative_index("L_cov", "N_predict", N_predict);
      current_statement__ = 22;
      L_cov = Eigen::Matrix<double, -1, -1>(N_predict, N_predict);
      stan::math::fill(L_cov, std::numeric_limits<double>::quiet_NaN());
      
      current_statement__ = 22;
      assign(L_cov, nil_index_list(), cholesky_decompose(cov),
        "assigning variable L_cov");
      current_statement__ = 23;
      validate_non_negative_index("f_tilde", "N_predict", N_predict);
      current_statement__ = 24;
      validate_non_negative_index("f_predict", "N_predict", N_predict);
      current_statement__ = 25;
      validate_non_negative_index("y_predict", "N_predict", N_predict);
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***"); 
    }
    num_params_r__ = 0U;
    
    try {
      num_params_r__ += N_predict;
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***"); 
    }
  }
  template <bool propto__, bool jacobian__, typename VecR, typename VecI, stan::require_vector_like_t<VecR>* = nullptr, stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr>
  inline stan::scalar_type_t<VecR> log_prob_impl(VecR& params_r__,
                                                 VecI& params_i__,
                                                 std::ostream* pstream__ = nullptr) const {
    using T__ = stan::scalar_type_t<VecR>;
    using local_scalar_t__ = T__;
    T__ lp__(0.0);
    stan::math::accumulator<T__> lp_accum__;
    static const char* function__ = "gaussian_process_model_namespace::log_prob";
(void) function__;  // suppress unused var warning

    stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void) DUMMY_VAR__;  // suppress unused var warning

    
    try {
      Eigen::Matrix<local_scalar_t__, -1, 1> f_tilde;
      f_tilde = Eigen::Matrix<local_scalar_t__, -1, 1>(N_predict);
      stan::math::fill(f_tilde, DUMMY_VAR__);
      
      current_statement__ = 1;
      f_tilde = in__.vector(N_predict);
      Eigen::Matrix<local_scalar_t__, -1, 1> f_predict;
      f_predict = Eigen::Matrix<local_scalar_t__, -1, 1>(N_predict);
      stan::math::fill(f_predict, DUMMY_VAR__);
      
      current_statement__ = 2;
      assign(f_predict, nil_index_list(), multiply(L_cov, f_tilde),
        "assigning variable f_predict");
      {
        current_statement__ = 4;
        lp_accum__.add(normal_lpdf<propto__>(f_tilde, 0, 1));
        current_statement__ = 5;
        lp_accum__.add(
          normal_lpdf<propto__>(y_obs,
            rvalue(f_predict,
              cons_list(index_multi(observed_idx), nil_index_list()),
              "f_predict"), sigma));
      }
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***"); 
    }
    lp_accum__.add(lp__);
    return lp_accum__.sum();
    } // log_prob_impl() 
    
  template <typename RNG, typename VecR, typename VecI, typename VecVar, stan::require_vector_like_vt<std::is_floating_point, VecR>* = nullptr, stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr, stan::require_std_vector_vt<std::is_floating_point, VecVar>* = nullptr>
  inline void write_array_impl(RNG& base_rng__, VecR& params_r__,
                               VecI& params_i__, VecVar& vars__,
                               const bool emit_transformed_parameters__ = true,
                               const bool emit_generated_quantities__ = true,
                               std::ostream* pstream__ = nullptr) const {
    using local_scalar_t__ = double;
    vars__.resize(0);
    stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
    static const char* function__ = "gaussian_process_model_namespace::write_array";
(void) function__;  // suppress unused var warning

    (void) function__;  // suppress unused var warning

    double lp__ = 0.0;
    (void) lp__;  // dummy to suppress unused var warning
    stan::math::accumulator<double> lp_accum__;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void) DUMMY_VAR__;  // suppress unused var warning

    
    try {
      Eigen::Matrix<double, -1, 1> f_tilde;
      f_tilde = Eigen::Matrix<double, -1, 1>(N_predict);
      stan::math::fill(f_tilde, std::numeric_limits<double>::quiet_NaN());
      
      current_statement__ = 1;
      f_tilde = in__.vector(N_predict);
      Eigen::Matrix<double, -1, 1> f_predict;
      f_predict = Eigen::Matrix<double, -1, 1>(N_predict);
      stan::math::fill(f_predict, std::numeric_limits<double>::quiet_NaN());
      
      for (int sym1__ = 1; sym1__ <= N_predict; ++sym1__) {
        vars__.emplace_back(f_tilde[(sym1__ - 1)]);}
      if (logical_negation((primitive_value(emit_transformed_parameters__) ||
            primitive_value(emit_generated_quantities__)))) {
        return ;
      } 
      current_statement__ = 2;
      assign(f_predict, nil_index_list(), multiply(L_cov, f_tilde),
        "assigning variable f_predict");
      if (emit_transformed_parameters__) {
        for (int sym1__ = 1; sym1__ <= N_predict; ++sym1__) {
          vars__.emplace_back(f_predict[(sym1__ - 1)]);}
      } 
      if (logical_negation(emit_generated_quantities__)) {
        return ;
      } 
      std::vector<double> y_predict;
      y_predict = std::vector<double>(N_predict, std::numeric_limits<double>::quiet_NaN());
      
      current_statement__ = 3;
      assign(y_predict, nil_index_list(),
        normal_rng(f_predict, sigma, base_rng__),
        "assigning variable y_predict");
      for (int sym1__ = 1; sym1__ <= N_predict; ++sym1__) {
        vars__.emplace_back(y_predict[(sym1__ - 1)]);}
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***"); 
    }
    } // write_array_impl() 
    
  template <typename VecVar, typename VecI, stan::require_std_vector_t<VecVar>* = nullptr, stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr>
  inline void transform_inits_impl(const stan::io::var_context& context__,
                                   VecI& params_i__, VecVar& vars__,
                                   std::ostream* pstream__ = nullptr) const {
    using local_scalar_t__ = double;
    vars__.clear();
    vars__.reserve(num_params_r__);
    
    try {
      int pos__;
      pos__ = std::numeric_limits<int>::min();
      
      pos__ = 1;
      Eigen::Matrix<double, -1, 1> f_tilde;
      f_tilde = Eigen::Matrix<double, -1, 1>(N_predict);
      stan::math::fill(f_tilde, std::numeric_limits<double>::quiet_NaN());
      
      {
        std::vector<local_scalar_t__> f_tilde_flat__;
        current_statement__ = 1;
        assign(f_tilde_flat__, nil_index_list(), context__.vals_r("f_tilde"),
          "assigning variable f_tilde_flat__");
        current_statement__ = 1;
        pos__ = 1;
        current_statement__ = 1;
        for (int sym1__ = 1; sym1__ <= N_predict; ++sym1__) {
          current_statement__ = 1;
          assign(f_tilde, cons_list(index_uni(sym1__), nil_index_list()),
            f_tilde_flat__[(pos__ - 1)], "assigning variable f_tilde");
          current_statement__ = 1;
          pos__ = (pos__ + 1);}
      }
      for (int sym1__ = 1; sym1__ <= N_predict; ++sym1__) {
        vars__.emplace_back(f_tilde[(sym1__ - 1)]);}
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***"); 
    }
    } // transform_inits_impl() 
    
  inline void get_param_names(std::vector<std::string>& names__) const {
    
    names__.clear();
    names__.emplace_back("f_tilde");
    names__.emplace_back("f_predict");
    names__.emplace_back("y_predict");
    } // get_param_names() 
    
  inline void get_dims(std::vector<std::vector<size_t>>& dimss__) const {
    dimss__.clear();
    dimss__.emplace_back(std::vector<size_t>{static_cast<size_t>(N_predict)});
    
    dimss__.emplace_back(std::vector<size_t>{static_cast<size_t>(N_predict)});
    
    dimss__.emplace_back(std::vector<size_t>{static_cast<size_t>(N_predict)});
    
    } // get_dims() 
    
  inline void constrained_param_names(
                                      std::vector<std::string>& param_names__,
                                      bool emit_transformed_parameters__ = true,
                                      bool emit_generated_quantities__ = true) const
    final {
    
    for (int sym1__ = 1; sym1__ <= N_predict; ++sym1__) {
      {
        param_names__.emplace_back(std::string() + "f_tilde" + '.' + std::to_string(sym1__));
      }}
    if (emit_transformed_parameters__) {
      for (int sym1__ = 1; sym1__ <= N_predict; ++sym1__) {
        {
          param_names__.emplace_back(std::string() + "f_predict" + '.' + std::to_string(sym1__));
        }}
    }
    
    if (emit_generated_quantities__) {
      for (int sym1__ = 1; sym1__ <= N_predict; ++sym1__) {
        {
          param_names__.emplace_back(std::string() + "y_predict" + '.' + std::to_string(sym1__));
        }}
    }
    
    } // constrained_param_names() 
    
  inline void unconstrained_param_names(
                                        std::vector<std::string>& param_names__,
                                        bool emit_transformed_parameters__ = true,
                                        bool emit_generated_quantities__ = true) const
    final {
    
    for (int sym1__ = 1; sym1__ <= N_predict; ++sym1__) {
      {
        param_names__.emplace_back(std::string() + "f_tilde" + '.' + std::to_string(sym1__));
      }}
    if (emit_transformed_parameters__) {
      for (int sym1__ = 1; sym1__ <= N_predict; ++sym1__) {
        {
          param_names__.emplace_back(std::string() + "f_predict" + '.' + std::to_string(sym1__));
        }}
    }
    
    if (emit_generated_quantities__) {
      for (int sym1__ = 1; sym1__ <= N_predict; ++sym1__) {
        {
          param_names__.emplace_back(std::string() + "y_predict" + '.' + std::to_string(sym1__));
        }}
    }
    
    } // unconstrained_param_names() 
    
  inline std::string get_constrained_sizedtypes() const {
    stringstream s__;
    s__ << "[{\"name\":\"f_tilde\",\"type\":{\"name\":\"vector\",\"length\":" << N_predict << "},\"block\":\"parameters\"},{\"name\":\"f_predict\",\"type\":{\"name\":\"vector\",\"length\":" << N_predict << "},\"block\":\"transformed_parameters\"},{\"name\":\"y_predict\",\"type\":{\"name\":\"array\",\"length\":" << N_predict << ",\"element_type\":{\"name\":\"real\"}},\"block\":\"generated_quantities\"}]";
    return s__.str();
    } // get_constrained_sizedtypes() 
    
  inline std::string get_unconstrained_sizedtypes() const {
    stringstream s__;
    s__ << "[{\"name\":\"f_tilde\",\"type\":{\"name\":\"vector\",\"length\":" << N_predict << "},\"block\":\"parameters\"},{\"name\":\"f_predict\",\"type\":{\"name\":\"vector\",\"length\":" << N_predict << "},\"block\":\"transformed_parameters\"},{\"name\":\"y_predict\",\"type\":{\"name\":\"array\",\"length\":" << N_predict << ",\"element_type\":{\"name\":\"real\"}},\"block\":\"generated_quantities\"}]";
    return s__.str();
    } // get_unconstrained_sizedtypes() 
    
  
    // Begin method overload boilerplate
    template <typename RNG>
    inline void write_array(RNG& base_rng,
                            Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                            Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                            const bool emit_transformed_parameters = true,
                            const bool emit_generated_quantities = true,
                            std::ostream* pstream = nullptr) const {
      std::vector<double> vars_vec(vars.size());
      std::vector<int> params_i;
      write_array_impl(base_rng, params_r, params_i, vars_vec,
          emit_transformed_parameters, emit_generated_quantities, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i) {
        vars.coeffRef(i) = vars_vec[i];
      }
    }

    template <typename RNG>
    inline void write_array(RNG& base_rng, std::vector<double>& params_r,
                            std::vector<int>& params_i,
                            std::vector<double>& vars,
                            bool emit_transformed_parameters = true,
                            bool emit_generated_quantities = true,
                            std::ostream* pstream = nullptr) const {
      write_array_impl(base_rng, params_r, params_i, vars, emit_transformed_parameters, emit_generated_quantities, pstream);
    }

    template <bool propto__, bool jacobian__, typename T_>
    inline T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
                       std::ostream* pstream = nullptr) const {
      Eigen::Matrix<int, -1, 1> params_i;
      return log_prob_impl<propto__, jacobian__>(params_r, params_i, pstream);
    }

    template <bool propto__, bool jacobian__, typename T__>
    inline T__ log_prob(std::vector<T__>& params_r,
                        std::vector<int>& params_i,
                        std::ostream* pstream = nullptr) const {
      return log_prob_impl<propto__, jacobian__>(params_r, params_i, pstream);
    }
  

    inline void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream = nullptr) const final {
      std::vector<double> params_r_vec(params_r.size());
      std::vector<int> params_i;
      transform_inits_impl(context, params_i, params_r_vec, pstream);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i) {
        params_r.coeffRef(i) = params_r_vec[i];
      }
    }
    inline void transform_inits(const stan::io::var_context& context,
                                std::vector<int>& params_i,
                                std::vector<double>& vars,
                                std::ostream* pstream = nullptr) const final {
      transform_inits_impl(context, params_i, vars, pstream);
    }        

};
}
using stan_model = gaussian_process_model_namespace::gaussian_process_model;

#ifndef USING_R

// Boilerplate
stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}

stan::math::profile_map& get_stan_profile_data() {
  return gaussian_process_model_namespace::profiles__;
}

#endif


